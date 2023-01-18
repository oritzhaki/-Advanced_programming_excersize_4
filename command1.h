#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND1_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND1_H

#include "command.h"

class Command1: public Command{
private:
    DefaultIO* io_;
    varHolder& var;
public:
    Command1(DefaultIO* io, varHolder& variables);
    void execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND1_H
