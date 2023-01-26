#include "SocketIO.h"

SocketIO::SocketIO(int client_sock): socket(client_sock) {}

string SocketIO::read() {
    // char * buffer = new char[this->BUFFER_SIZE];
    // memset(buffer,0,this->BUFFER_SIZE);
    // int read_bytes = recv(this->socket, buffer, this->BUFFER_SIZE, 0);
    // if(read_bytes < 0){
    //     return "Server: error reading from socket, goodbye!";
    // }
    // buffer[read_bytes] = '\0';
    // string output = string(buffer);
    // //cout << "in socketio read: " << output << endl;
    // delete[] buffer;
    // return output;
    string message;
    int bytes_received = 0;
    int total = 0;
    char * buffer = new char[this->BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    while ((bytes_received = recv(this->socket, buffer, this->BUFFER_SIZE, 0)) > 0) {
        if(bytes_received == this->BUFFER_SIZE) {
            // total += bytes_received;
            // buffer_size *= 2;
            // char * new_buffer = new char[buffer_size];
            // memset(new_buffer, 0, sizeof(new_buffer));
            // memcpy(new_buffer, buffer, buffer_size);
            
            // buffer = new_buffer;
            // delete[] new_buffer;
            string str = string(buffer);
            cout << "STR:" << str << endl;
            message.append(str);
        }else {
            string str = string(buffer);
            cout << "STR:" << str << endl;

            message.append(str);
            break;
        }
    }
    if (bytes_received < 0) {
    return "";
    }
    // message.append(buffer, bytes_received + total);
    // std::cout << "message:" << message << "." << std::endl;
    if(message.size() == 0) { // if message is empty it means that there is invalid path in client side so abort
        cout << "inside" << endl;
        throw false;
    }
    // if(message.find("\0") != string::npos) {
    //     cout << "ARRIVE TO LINE 50" << endl;
    //     std::cout << message.size() << std::endl;
    //     size_t pos = message.find("\0");
    //     message = message.substr(0,pos-1);
    //     std::cout << message.size() << std::endl;
    // }
    // std::cout << message.size() << std::endl;
    
    // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // cout << "Buffer:" << buffer << "." << endl;
    delete[] buffer;
    return message;
}

// Method to write data to the socket
void SocketIO::write(const string& data) {
    const string& output = data;
    //cout << "in socketio write: " << string(output) << endl;
    int sentBytes = send(this->socket, output.c_str(), output.size(), 0);
    if (sentBytes < 0){   // send fails
        perror("Server: error sending to client, goodbye!");
    }
}

// Method to write data to the socket
int SocketIO::writeFromFile(const string& data) {
    const string& output = data;
    //cout << "in socketio write: " << string(output) << endl;
    int sentBytes = send(this->socket, output.c_str(), output.size() + 1, 0);
    if (sentBytes < 0){   // send fails
        perror("Server: error sending to client, goodbye!");
    }
    return sentBytes;
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
        while (file.get(c)) {
            fileContents += c;
        }

        file.close();

        return fileContents;

    } else {
        throw false;
    }
}

// Method to create local server data file
void SocketIO::saveData(string fileName) {
    // string message;
    // int bytes_received = 0;
    // int total = 0;
    // int buffer_size = 4096;
    // char * buffer = new char[buffer_size];
    // memset(buffer, 0, sizeof(buffer));

    // while ((bytes_received = recv(this->socket, buffer, buffer_size, 0)) > 0) {
    //     if(bytes_received == buffer_size) {
    //         // total += bytes_received;
    //         // buffer_size *= 2;
    //         // char * new_buffer = new char[buffer_size];
    //         // memset(new_buffer, 0, sizeof(new_buffer));
    //         // memcpy(new_buffer, buffer, buffer_size);
            
    //         // buffer = new_buffer;
    //         // delete[] new_buffer;
    //         message.append(buffer, bytes_received);
    //     }else {
    //         message.append(buffer, bytes_received);
    //         break;
    //     }
    // }
    // if (bytes_received < 0) {
    // return;
    // }
    // // message.append(buffer, bytes_received + total);
    // // std::cout << "message:" << message << "." << std::endl;
    // if(message.size() == 1) { // if message is empty it means that there is invalid path in client side so abort
    //     cout << "inside" << endl;
    //     throw false;
    // }
    
    // std::cout << message.size() << std::endl;
    
    // // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // // cout << "Buffer:" << buffer << "." << endl;
    // delete[] buffer;
    string message = this->read();
    this->writeFile(fileName, message); // write local file
    // cout << "AFTER WRITE FILE" << endl;
   
}

// Method to close the socket
void SocketIO::close() {
    ::shutdown(this->socket, SHUT_RDWR);
    ::close(this->socket);
}
