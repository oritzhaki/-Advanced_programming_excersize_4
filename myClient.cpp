#include "myClient.h"
#include "clientUtilityFunctions.h"

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
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        cerr << "Error creating socket" << endl;
        return;
    }

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
    if (connect(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        cerr << "Error connecting to server" << endl;
        return;
    }

    cout << "Connected to server at " << ip_address << ": " << port << endl;

    // Run an infinite loop to get a vector from the user
    while (true) {
        
        string input;
        getline(cin, input);

        if (input == "-1") {
            // Close the socket and program
            break;
        }

        if (!userInputValidation(input)) { // if input invalid, don't send to server and ask again for user input
            continue;
       
        } else { // if input valid -> send to server
       
            // Send the input to the server
            send(sockfd, input.c_str(), input.size(), 0);

            // Receive the response from the server
            char buffer[BUFFER_SIZE];
            int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (bytes_received < 0) {
                // connection is closed
                cerr << "Error receiving data from server" << endl;
                break;
            }

            // Received messege from server
            cout << string(buffer, bytes_received) << endl;
            
        }
    }

    // Close the socket
    close(sockfd);

    // Close client 
    return;
}


