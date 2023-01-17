#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND1_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND1_H

#include "command.h"

class Command1: public Command{
private:
    DefaultIO dio;
    varHolder var;
public:
    Command1(DefaultIO dio, varHolder &variables);
    void execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND1_H
