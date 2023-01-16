#include "SocketIO.h"

void SocketIO::connect(const char* ipAddress, int port) {
    this->socket = ::socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(ipAddress);
    serverAddress.sin_port = htons(port);

    ::connect(this->socket, (sockaddr*) &serverAddress, sizeof(serverAddress));
}

// Method to read data from the socket
string SocketIO::read() {
    char buffer[4096];
    int bytesReceived = ::read(this->socket, buffer, sizeof(buffer));
    return string(buffer, bytesReceived);
}

// Method to write data to the socket
void SocketIO::write(const string& data) {
    ::write(this->socket, data.c_str(), data.size());
}

// Method to read a file's contents
DBReader SocketIO::readFile(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        throw runtime_error("Error: Could not open file: " + filePath);
    }
    string contents((istreambuf_iterator<char>(file)),
                            istreambuf_iterator<char>());
    return contents;
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
