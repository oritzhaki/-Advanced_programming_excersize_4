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

using namespace std;

const int BUFFER_SIZE = 4096;

class MyClient {
public:    
    // MyClient() {};
    void run(int argc, char** argv);

};


#endif