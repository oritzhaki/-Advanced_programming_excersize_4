#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND2_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND2_H

#include "command.h"

class Command2: public Command{
public:
    Command2() : Command("algorithm settings"){};
    void execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND2_H
