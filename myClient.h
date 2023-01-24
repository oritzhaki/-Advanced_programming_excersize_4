#ifndef EXERCISE_3_MYCLIENT_H
#define EXERCISE_3_MYCLIENT_H

#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <unistd.h>
#include <vector>
#include <pthread.h>
#include <fcntl.h>
#include <queue>
#include <thread>
#include <chrono>
#include "SocketIO.h"
#include "DefaultIO.h"

using namespace std;

class MyClient {
public:    
    // MyClient() {};
    void run(int argc, char** argv);
    void sendData(string message, DefaultIO* io);
};


#endif