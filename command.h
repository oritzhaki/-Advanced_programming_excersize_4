#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND_H


#include "DefaultIO.h"
#include <string>
using namespace std;

struct Variables {
    DBReader trainDB;
    DBReader testDB;
    int k = 5; // init with default value
    string metric = "AUC"; // init with default value
};

class Command {
public:
    Command(string description):description(description){};
   // virtual ~Command() {}
    virtual void execute() {};
    string getDescription(); 
private:
    string description;
    DefaultIO io;
};


#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND_H
