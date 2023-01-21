#include "myClient.h"
#include "clientUtilityFunctions.h"

struct ThreadData {
    DefaultIO* io;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    queue<string> messages;
    int socket;
};

void* receive_from_server(void* arg) {    // receive data from the server
    ThreadData* data = (ThreadData*) arg;
    while(true){
        string message = data->io->read(); // get message from server
        cout << message << endl;
        pthread_mutex_lock(&data->mutex); // lock
        data->messages.push(message); // add to queue
        pthread_cond_signal(&data->cond); // signal that a new message is available
        pthread_mutex_unlock(&data->mutex); // unlock
    }
    return 0;
}

void* send_to_server(void* arg) {    // send data to the server
    ThreadData* data = (ThreadData*) arg;
    while(true){
        string message;
        pthread_mutex_lock(&data->mutex); // lock
        getline(cin, message); // insert message
        data->messages.push(message);
        pthread_mutex_unlock(&data->mutex); // unlock
        data->io->write(message); // send to server
    }
    return 0;
}

void MyClient::run(int argc, char** argv) {
    // make sure there are 3 arguments to activate client
    if (argc < 3) {
        cerr << "Usage: client.out IP_ADDRESS PORT" << endl;
        return;
    }

    // Parse the IP address and port number
    const char* ip_address = argv[1];
    const int port = stoi(argv[2]);

    // Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        cerr << "Error creating socket" << endl;
        return;
    }

    // connect to the server
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(ip_address);
    serverAddr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_address, &serverAddr.sin_addr) <= 0) {
        cerr << "Error parsing IP address" << endl;
        return;
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        cerr << "Error connecting to server" << endl;
        return;
    }

    pthread_t receive_thread; // create a receive thread
    pthread_t send_thread; // create a send thread
    // create the thread data:
    ThreadData data;
    data.io = new SocketIO(client_socket);
    data.socket = client_socket;
    pthread_mutex_init(&data.mutex, NULL);
    pthread_cond_init(&data.cond, NULL);
    while (!data.messages.empty()) {
        data.messages.pop();
    }

    // send threads to interact with server
    pthread_create(&receive_thread, NULL, receive_from_server, &data);
    pthread_create(&send_thread, NULL, send_to_server, &data);
   
    // wait for the receive thread to finish
    pthread_join(receive_thread, NULL);
    pthread_join(send_thread, NULL);
    //pthread_mutex_destroy();

    // close the socket
    close(client_socket);

    // Close client
    return;
}

 

