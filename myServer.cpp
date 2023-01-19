#include "myServer.h"

MyServer::MyServer(){
    this->threadStatus.resize(this->THREAD_POOL_SIZE, true);
}

void MyServer::handleClient(int sock) { // for one client

    // int threadId = *(int *)arg;
    int clientSock = sock;

        // pthread_mutex_lock(&queue_lock);
        // while (this->threadStatus[threadId] == false) {
        //     pthread_cond_wait(&queue_cond, &queue_lock);
        // }
        // clientSock = clientSockets.front();
        // clientSockets.erase(clientSockets.begin()); // erase top socket 
        // threadStatus[threadId] = false;
        // pthread_mutex_unlock(&queue_lock);

        // Handle client socket
        
    DefaultIO *io = new SocketIO(clientSock);
    CLI cli(io);
    cli.start();
        // if we got here user doesn't want to play anymore
        // delete io;
        // io->write("goodbye!");

    close(clientSock);
    // pthread_mutex_lock(&queue_lock);
    // threadStatus[threadId] = true;
    // pthread_cond_signal(&queue_cond);
    // pthread_mutex_unlock(&queue_lock);
    
    
    // int client_sock = *(int *)arg;

    // char buffer[1024];
    // while (true) {
    //     memset(buffer, 0, sizeof(buffer));
    //     int recv_size = recv(client_sock, buffer, sizeof(buffer), 0);
    //     if (recv_size <= 0) {
    //         break;
    //     }
    //     std::cout << "Received data from client: " << buffer << std::endl;
    //     send(client_sock, buffer, recv_size, 0);
    // }

    // close(client_sock);
    // pthread_exit(NULL);
}

// the server is activated by: server.out file port
void MyServer::runServer(int argc, char** argv) {
    // make sure there are 3 arguments to activate client 
    if (argc != 2) {
        cerr << "Usage: server.out PORT" << endl;
        return;
    }
    int server_port;
    try{ // checking port validation
        server_port = stoi(argv[1]);
        if((server_port < 1024) || (server_port > 65535)){
            throw false;
        }
    } catch (...){
        cout << "Server: Invalid port, goodbye!" << endl;
        return;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0); // sock is the socket descriptor (socket ID)
    // SOCKSTREAM is communication type TPC. AF_NET is the communication domain for IPV4 (IP of different hosts)
    if(sock < 0){ // creation fails
        perror("Server: error creating socket, goodbye!");
        return;
    }

    struct sockaddr_in sin; // the socket address (IP+port)
    memset(&sin, 0, sizeof(sin)); // sets sin to zeros
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port); // converts port to bytes
    if(bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0){  // binding socket to port
        perror("Server: error binding socket, goodbye!");
        return;
    }

    while(true) { // new client - new thread
        
        if(listen(sock, 100) < 0){ // puts the server socket in a passive mode and waits for the client to make a connection.
        perror("Server: error listening to socket, goodbye!");
        return;
        }
    
        struct sockaddr_in client_sin; // the socket address (IP+port)
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len); // create connection socket, ready to transfer data
        if(client_sock < 0){  // creation/connection fails
            perror("Server: error accepting client, goodbye!");
            continue; // get new client
        }

        this->handleClient(client_sock);
    
        // this->clientSockets.push_back(client_sock);
        // pthread_t threads[THREAD_POOL_SIZE];
        // int thread_id[THREAD_POOL_SIZE];
        // pthread_mutex_init(&queue_lock, NULL);
        // pthread_cond_init(&queue_cond, NULL);

        // for (int i = 0; i < THREAD_POOL_SIZE; i++) {
        //     thread_id[i] = i;
        //     pthread_create(&threads[i], NULL, this->handleClient, (void *)&thread_id[i]);
        // }

        // while(true) { // for one client
        //     DefaultIO *io = new SocketIO(client_sock);
        //     CLI cli(io);
        //     cli.start();
        //     // if we got here user doesn't want to play anymore
        //     // delete io;
        //     // io->write("goodbye!");
        //     break;
        // }

    }
    close(sock); 
    return;


//    string filename = argv[1];
//    DBReader newReader;
//    try{ //check file validation
//        newReader.readerInit(filename);
//    } catch (...){
//        // file doesnt exist/not valid OR bad value in file OR no consistant vector length
//        cout << "Server: Invalid file, goodbye!" << endl;
//        return;
//    }

    // int sock = socket(AF_INET, SOCK_STREAM, 0); // sock is the socket descriptor (socket ID)
    // // SOCKSTREAM is communication type TPC. AF_NET is the communication domain for IPV4 (IP of different hosts)
    // if(sock < 0){ // creation fails
    //     perror("Server: error creating socket, goodbye!");
    //     return;
    // }

    // struct sockaddr_in sin; // the socket address (IP+port)
    // memset(&sin, 0, sizeof(sin)); // sets sin to zeros
    // sin.sin_family = AF_INET;
    // sin.sin_addr.s_addr = INADDR_ANY;
    // sin.sin_port = htons(server_port); // converts port to bytes
    // if(bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0){  // binding socket to port
    //     perror("Server: error binding socket, goodbye!");
    //     return;
    // }

    // if(listen(sock, 100) < 0){ // puts the server socket in a passive mode and waits for the client to make a connection.
    //     perror("Server: error listening to socket, goodbye!");
    //     return;
    // }

    // while(true) { // new client - new thread
    //     struct sockaddr_in client_sin; // the socket address (IP+port)
    //     unsigned int addr_len = sizeof(client_sin);
    //     int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len); // create connection socket, ready to transfer data
    //     if(client_sock < 0){  // creation/connection fails
    //         perror("Server: error accepting client, goodbye!");
    //         continue; // get new client
    //     }

    //     while(true){ // same client
    //         //CLI cli():
    //         //cli.start()

    //         char buffer[4096];
    //         int expected_data_len = sizeof(buffer); // the size of the buffer is the maximum received data length
    //         memset(buffer,0,expected_data_len);
    //         int read_bytes = recv(client_sock, buffer, expected_data_len, 0);

    //         if(read_bytes == 0){
    //             //connection is closed by client
    //             break;
    //         }else if(read_bytes < 0){
    //             perror("Server: error reading from socket, goodbye!");
    //             break;
    //         }else{ // check input from client
    //             string stroutput;
    //             // translate char *  to string
    //             string strbuffer = string(buffer);
    //             try{
    //                 stroutput = tryClassification(strbuffer, newReader.getXtrain(), newReader.getYtrain());
    //             } catch (...){ // if received invalid input from client
    //                 stroutput = "invalid input";
    //             }
    //             //translate string to char *
    //             const int length = stroutput.length();
    //             char* output = new char[length + 1];// declaring character array (+1 for null terminator)
    //             strcpy(output, stroutput.c_str());// copying the contents of the string

    //             int sent_bytes = send(client_sock, output, strlen(output), 0);
    //             if (sent_bytes < 0){   // send fails
    //                 perror("Server: error sending to client, goodbye!");
    //                 delete[] output;
    //                 break;
    //             }

    //             delete[] output;
    //         }
    //     } //  be ready to receive again

    // }
    // close(sock); 
    // return;
}
