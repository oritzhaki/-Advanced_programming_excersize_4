#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND1_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND1_H

#include "command.h"

class Command1: public Command{
public:
    Command1() : Command("upload an unclassified csv data file"){}
    void execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND1_H
