#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND2_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND2_H

#include "command.h"

class Command2: public Command{
private:
    DefaultIO* io_;
    varHolder& var;
public:
    Command2(DefaultIO* io, varHolder& variables);
    void execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND2_H
