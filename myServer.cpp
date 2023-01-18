#include "serverUtilityFunctions.h"
#include "myServer.h"
#include "reader.h"
#include "CLI.h"


// the server is activated by: server.out file port
// void MyServer::runServer(char** argv){
void MyServer::runServer(){

    while(true) { // for one client
        CLI cli(new StandardIO);
        cli.start();
    }
//     int server_port;
//     try{ // checking port validation
//         server_port = stoi(argv[2]);
//         if((server_port < 1024) || (server_port > 65535)){
//             throw false;
//         }
//     } catch (...){
//         cout << "Server: Invalid port, goodbye!" << endl;
//         return;
//     }

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
