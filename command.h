#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND_H

#include <string>
using namespace std;

class Command {
public:
    Command(string description):description_(description){}
    virtual ~Command() {}
    virtual void execute() = 0;
    string getDescription() { return description_;}

private:
    string description_;
};


#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND_H
