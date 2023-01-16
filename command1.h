#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND1_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND1_H

#include "command.h"

class Command1: public Command{
public:
    Command1(DefaultIO dio);
    DefaultIO dio;
    DBReader trainReader;
    DBReader testReader;  // maybe take DBReader and add a flag to distinct between train and test
    void execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND1_H
