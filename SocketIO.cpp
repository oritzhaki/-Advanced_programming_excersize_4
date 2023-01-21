#include "SocketIO.h"

SocketIO::SocketIO(int client_sock): socket(client_sock) {}

string SocketIO::read() {
    char * buffer = new char[BUFFER_SIZE];
    memset(buffer,0,BUFFER_SIZE);
    int read_bytes = recv(this->socket, buffer, BUFFER_SIZE, 0);
    if(read_bytes < 0){
        return "Server: error reading from socket, goodbye!";
    }
    buffer[read_bytes] = '\0';
    string output = string(buffer);
    //cout << "in socketio read: " << output << endl;
    delete[] buffer;
    return output;
}

// Method to write data to the socket
void SocketIO::write(const string& data) {
    const string& output = data;
    //cout << "in socketio write: " << string(output) << endl;
    int sent_bytes = send(this->socket, output.c_str(), output.size() + 1, 0);
    if (sent_bytes < 0){   // send fails
        perror("Server: error sending to client, goodbye!");
    }
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
