#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND_H


#include "DefaultIO.h"
#include "varHolder.h"
#include <string>
using namespace std;


class Command {
public:
    Command(string description):description(description){};
   // virtual ~Command() {}
    virtual void execute() {};
    string getDescription(){ return this->description;};
private:
    string description;
};


#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND_H
