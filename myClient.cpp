#include "myClient.h"
#include "clientUtilityFunctions.h"

#include <iostream>
#include <pthread.h>
#include <string>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void* receive_from_server(void* client_socket) {
    // receive data from the server
    char buffer[4096];
    int bytes_received = recv(*((int*) client_socket), buffer, sizeof(buffer), 0);
    if (bytes_received > 0) {
        cout << buffer << endl;
    }
    return 0;
}

void* send_to_server(void* client_socket) {
    // send data to the server
    string message;
    getline(cin, message);
    send(*((int*) client_socket), message.c_str(), message.size(), 0);
    // while (getline(cin, message)) {
    //     send(*((int*) client_socket), message.c_str(), message.size(), 0);
    // }
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
        // Set up the server address
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
    while (true) {
        // receive_from_server((void*) &client_socket);
        // send_to_server((void*) &client_socket);
        pthread_create(&receive_thread, NULL, receive_from_server, (void*) &client_socket);
        pthread_create(&send_thread, NULL, send_to_server, (void*) &client_socket);
    }
   
    // wait for the receive thread to finish
    pthread_join(receive_thread, NULL);
    pthread_join(send_thread, NULL);

    // close the socket
    close(client_socket);

    // Close client    
    return;

   

    // // Run an infinite loop to get a vector from the user
    // while (true) {
        
    //     string input;
    //     getline(cin, input);

    //     if (input == "-1") {
    //         // Close the socket and program
    //         break;
    //     }

    //     if (!userInputValidation(input)) { // if input invalid, don't send to server and ask again for user input
    //         continue;
       
    //     } else { // if input valid -> send to server
       
    //         // Send the input to the server
    //         send(client_socket, input.c_str(), input.size(), 0);

    //         // Receive the response from the server
    //         char buffer[BUFFER_SIZE];
    //         int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    //         if (bytes_received < 0) {
    //             // connection is closed
    //             cerr << "Error receiving data from server" << endl;
    //             break;
    //         }

    //         // Received messege from server
    //         cout << string(buffer, bytes_received) << endl;
            
    //     }
}

 

