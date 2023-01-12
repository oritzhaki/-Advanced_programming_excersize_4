#ifndef EXERCISE_3_MYSERVER_H
#define EXERCISE_3_MYSERVER_H

#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

class MyServer {
public:
    void runServer(char** argv);
};

#endif
