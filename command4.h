#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND4_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND4_H

#include "command.h"

class Command4: public Command{
public:
    Command4(DefaultIO dio);
    DefaultIO dio;
    void execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND4_H
