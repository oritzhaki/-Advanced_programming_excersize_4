#include "myClient.h"
#include "clientUtilityFunctions.h"
#include <mutex>


// void* Data(void* args) {
//      cout << "PASS FUNC" << endl;
//     thread_args* arg = (struct thread_args*) args;
//     int socket = arg->sock;
//     string path = arg->path;
//     DefaultIO* io = new SocketIO(socket);

//     string message;
//     int bytes_received = 0;
//     int total = 0;
//     int buffer_size = 4096;
//     char * buffer = new char[buffer_size];
//     memset(buffer, 0, sizeof(buffer));
        
//     while ((bytes_received = recv(socket, buffer, buffer_size, 0)) > 0) {
//         if(bytes_received == buffer_size) {
//             // total += bytes_received;
//             // buffer_size *= 2;
//             // char * new_buffer = new char[buffer_size];
//             // memset(new_buffer, 0, sizeof(new_buffer));
//             // memcpy(new_buffer, buffer, buffer_size);
//             // buffer = new_buffer;
//             // delete[] new_buffer;
//             message.append(buffer, bytes_received);

//         }else {
//             message.append(buffer, bytes_received);
//             break;
//         }
//     }
//     if (bytes_received < 0) {
//         void* result;
//         pthread_exit(result);
//     }
//     std::cout << "message:" << message << "." << std::endl;
//     if(message.size() == 1) { // if message is empty it means that there is invalid path in client side so abort
//         cout << "inside" << endl;
//         throw false;
//     }
//     std::cout << message.size() << std::endl;
    
//     std::this_thread::sleep_for(std::chrono::milliseconds(100));
//     // cout << "Buffer:" << buffer << "." << endl;
//     delete[] buffer;
//     io->writeFile(path, message); // write local file
//     // cout << "AFTER WRITE FILE" << endl;
//     void* result;
//     pthread_exit(result); 
// }

// void write_to_file(int sock){
//     try{
//         pthread_t download_thread;
//         // DefaultIO *io = new SocketIO(sock);
//         // io->write("READY_TO_SAVE");
//         // DefaultIO* io = ((DefaultIO*) arg);
//         // io->write("");
//         string path;
//         getline(cin, path); // get path from user to save results
//         thread_args args = {sock, path};
//         pthread_create(&download_thread, NULL, Data, (void*) &args); 
//         pthread_detach(download_thread);
//         // this_thread::sleep_for(chrono::milliseconds (100));
//         // io->write("");
//     }catch(runtime_error& e){
//         cout << e.what();
//     }
// }

int socketCreation(int server_port, char *ip_address) {
    // Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        cerr << "Error creating socket" << endl;
        return -1;
    }

    // connect to the server
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(ip_address);
    serverAddr.sin_port = htons(server_port);
    if (inet_pton(AF_INET, ip_address, &serverAddr.sin_addr) <= 0) {
        cerr << "Error parsing IP address" << endl;
        return -1;
    }
   
    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        cerr << "Error connecting to server" << endl;
        return -1;
    }
    return client_socket;

}

// Method to send local data from client to server
void MyClient::sendData(string message, DefaultIO* dio) {
    DefaultIO *io = dio;
    
    cout << message << endl;
    string path;
    getline(cin, path);
    string fileContent;
    try {
        fileContent = io->readFile(path);
    } catch(...) {
        throw false;
    }

    io->write(fileContent);

}

void MyClient::run(int argc, char** argv) {
    // make sure there are 3 arguments to activate client
    if (argc < 3) {
        cerr << "Usage: client.out IP_ADDRESS PORT" << endl;
        return;
    }

    // Parse the IP address and port number
    char* ip_address = argv[1];
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

    DefaultIO *io = new SocketIO(client_socket);
    while(true){
        cout << "BEGIN LOOP IN CLIENT" << endl;
        string input;
        // cout << "BEFORE READ" << endl;
        string message = io->read();
        // cout << "AFTER READ" << endl;
        if(message == "Please upload your local train CSV file.") {
            try {
                this_thread::sleep_for(std::chrono::milliseconds(100));
                sendData(message, io); // upload train data
                // read another message from server
                string newMessage = io->read();   // iris_classified.csv
                sendData(newMessage, io); // upload test data

            } catch(...) {
                 // path doesn't exist
                 io->write("");
            }        
            continue;    
        } 
        else if(message == "upload results:"){
            // receive the random port generated by server
            string newPort = io->read();
            int port = stoi(newPort);
            int newSock = socketCreation(port, ip_address);
            string path;
            getline(cin, path); // get path from user to save results
             // download file in a separate thread to allow user to continue sending requests
            thread client_thread([newSock, path]() {
                cout << "IN CLIENT THREAD" << endl;
                SocketIO* sio = new SocketIO(newSock);
                sio->saveData(path);
                delete sio;
                close(newSock);
                cout << "END CLIENT THREAD" << endl;
            });
            // Detach the thread so that it can run independently
            client_thread.detach();
            cout << "DETACH THRED" << endl;
            // write_to_file(newSock);
            continue;
        }
        else if(message == "EXIT"){ // user pressed 8 so exit
            break;
        
        } else { 
            cout << message << endl;
            getline(cin, input);
            io->write(input);
        }
    }

    delete io;

    // close the socket
    close(client_socket);

    // Close client
    return;
}

 

