#ifndef EXERCISE_3_MYSERVER_H
#define EXERCISE_3_MYSERVER_H

#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "CLI.h"
#include "SocketIO.h"
#include "StandardIO.h"
#include "reader.h"
#include "serverUtilityFunctions.h"

class MyServer {
private:
    const int THREAD_POOL_SIZE = 4;
    vector<int> clientSockets;
    pthread_mutex_t queue_lock;
    pthread_cond_t queue_cond;
    vector<bool> threadStatus;
    int next_thread = 0;
public:
    MyServer();
    void handleClient(int sock);
    void runServer(int argc, char** argv);
    
};

#endif
