#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND5_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND5_H

#include "command.h"

class Command5: public Command{
public:
    Command5(DefaultIO dio);
    DefaultIO dio;
    void execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND5_H
