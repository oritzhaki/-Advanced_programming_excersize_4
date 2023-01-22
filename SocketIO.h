#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <stdio.h> 
#include "DefaultIO.h"

using namespace std;

const int BUFFER_SIZE = 8192;

class SocketIO : public DefaultIO{
private:
    int socket;
public:
    SocketIO(int client_sock);
    // void connect(const char* ipAddress, int port);
    string read();
    void write(const string& data);
    void writeFile(const string& filePath, const string& contents);
    void close();
};