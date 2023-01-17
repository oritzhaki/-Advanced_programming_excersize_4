#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND4_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND4_H

#include "command.h"

class Command4: public Command{
private:
    DefaultIO dio;
    varHolder var;
public:
    Command4(DefaultIO dio, varHolder &variables);
    void execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND4_H
