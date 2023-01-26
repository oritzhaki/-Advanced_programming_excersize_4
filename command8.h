#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND8_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND8_H

#include "command.h"

class Command8: public Command{
private:
    DefaultIO* io_;
    varHolder& var;
public:
    Command8(DefaultIO* io, varHolder& variables);
    string execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND8_H