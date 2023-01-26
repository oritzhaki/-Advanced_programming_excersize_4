#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND5_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND5_H

#include "command.h"
#include "myServer.h"
class Command5: public Command{
private:
    DefaultIO* io_;
    varHolder& var;
public:
    Command5(DefaultIO* io, varHolder& variables);
    string execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND5_H
