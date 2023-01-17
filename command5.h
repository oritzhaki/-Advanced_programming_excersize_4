#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND5_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND5_H

#include "command.h"

class Command5: public Command{
private:
    DefaultIO dio;
    varHolder var;
public:
    Command5(DefaultIO dio, varHolder &variables);
    void execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND5_H
