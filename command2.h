#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND2_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND2_H

#include "command.h"

class Command2: public Command{
private:
    DefaultIO dio;
    varHolder var;
public:
    Command2(DefaultIO dio, varHolder &variables);
    void execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND2_H
