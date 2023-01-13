#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND5_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND5_H

#include "command.h"

class Command5: public Command{
public:
    Command5() : Command("download results"){}
    void execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND5_H
