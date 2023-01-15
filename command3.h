#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND3_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND3_H

#include "command.h"

class Command3: public Command{
public:
    Command3(DefaultIO dio);
    DefaultIO dio;
    void execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND3_H
