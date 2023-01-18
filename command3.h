#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND3_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND3_H

#include "command.h"
#include "knn.h"

class Command3: public Command{
private:
    DefaultIO dio;
    varHolder var;
public:
    Command3(DefaultIO dio, varHolder &variables);
    void execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND3_H
