#ifndef EXERCISE_3_CLIENTUTILITYFUNCTIONS_H
#define EXERCISE_3_CLIENTUTILITYFUNCTIONS_H

#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <unistd.h>
#include <vector>
#include <sstream>

using namespace std;

// bool isValidNumber(string temp, size_t offSet);
bool isValidNumber(const string& temp);
bool userInputValidation(string input);

#endif
