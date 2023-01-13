#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND_H

#include <string>
using namespace std;

class Command {
public:
    Command(string description):description(description){}
    virtual ~Command() {}
    virtual void execute() {}
    string getDescription() { return description;}
private:
    string description;
    // dio = DefaultIO
};


#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND_H
