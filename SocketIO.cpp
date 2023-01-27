#include "SocketIO.h"

SocketIO::SocketIO(int client_sock): socket(client_sock) {}

string SocketIO::read() {

    string message;
    int bytes_received = 0;
    string str;
    char * buffer = new char[this->BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    while ((bytes_received = recv(this->socket, buffer, this->BUFFER_SIZE, 0)) > 0) {
        if(bytes_received == this->BUFFER_SIZE) {
            str = string(buffer);
            message.append(str);
        }else {
            str = string(buffer);
            message.append(str);
            break;
        }
    }
    if (bytes_received < 0) {
    return "";
    }

    if(message.size() == 0) { // if message is empty it means that there is invalid path in client side so abort
        // cout << "inside" << endl;
        throw false;
    }

    delete[] buffer;
    return message;
}

// Method to write data to the socket
void SocketIO::write(const string& data) {
    const string& output = data;
    //cout << "in socketio write: " << string(output) << endl;
    int sentBytes = send(this->socket, output.c_str(), output.size() + 1, 0);
    if (sentBytes < 0){   // send fails
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
    file.close();
}

// Method to read a file's contents
string SocketIO::readFile(const string& filePath) {
    string fileContents;
    char c;
    ifstream file(filePath, ios::binary);
    if (file.is_open()) {
        while (file.get(c)) {fileContents += c;}

        file.close();
        return fileContents;

    } else {
        throw false;
    }
}

// Method to create local server data file
void SocketIO::saveData(string fileName) {
    string message;
    int bytes_received = 0;
    int total = 0;
    int buffer_size = 4096;
    char * buffer = new char[buffer_size];
    memset(buffer, 0, sizeof(buffer));

    while ((bytes_received = recv(this->socket, buffer, buffer_size, 0)) > 0) {
        if(bytes_received == buffer_size) {
            message.append(buffer, bytes_received);
        } else { message.append(buffer, bytes_received);break;}
    }
    if(bytes_received < 0) {return;}
    
    if(message.size() == 1) { // if message is empty it means that there is invalid path in client side so abort
        // cout << "inside" << endl;
        throw false;
    }
    // std::cout << message.size() << std::endl;

    delete[] buffer;
    // string message = this->read();
    this->writeFile(fileName, message); // write local file
   
}

