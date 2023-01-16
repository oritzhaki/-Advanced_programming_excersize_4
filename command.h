#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND_H


#include "DefaultIO.h"
#include <string>
using namespace std;

struct Variables {
//    int k = 5; // init with default value
//    string metric = "AUC"; // init with default value
    int k;
    string metric;
    DBReader initiated_trainDB;
    DBReader initiated_testDB;
};

class Command {
public:
    Command(string description):description(description){};
   // virtual ~Command() {}
    virtual void execute() {};
    string getDescription(){ return this->description;}
private:
    string description;
    DefaultIO io;
};


#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND_H
