#include "SocketIO.h"

SocketIO::SocketIO(int client_sock) {
    this->socket = client_sock;
}

string SocketIO::read() {
    char buffer[4096];
    int expected_data_len = sizeof(buffer); // the size of the buffer is the maximum received data length
    memset(buffer,0,expected_data_len);
    int read_bytes = recv(this->socket, buffer, expected_data_len, 0);

    if(read_bytes < 0){
        return "Server: error reading from socket, goodbye!";
    } 
    // char buffer[4096];
    // int bytesReceived = ::read(this->socket, buffer, sizeof(buffer));
    // return string(buffer, bytesReceived);
  
    return string(buffer);
}

// Method to write data to the socket
void SocketIO::write(const string& data) {
    const string& output = data + '\n';
    int sent_bytes = send(this->socket, output.c_str(), output.size(), 0);
    if (sent_bytes < 0){   // send fails
        perror("Server: error sending to client, goodbye!");
        
    }
    // ::write(this->socket, data.c_str(), data.size());

}


// Method to write a string to a file
void SocketIO::writeFile(const string& filePath, const string& contents) {
    ofstream file(filePath);
    if (!file.is_open()) {
        throw runtime_error("Error: Could not open file: " + filePath);
    }
    file << contents;
}

// Method to close the socket
void SocketIO::close() {
    ::shutdown(this->socket, SHUT_RDWR);
    ::close(this->socket);
}
