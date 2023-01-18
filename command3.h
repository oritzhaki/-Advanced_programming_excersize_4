#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND3_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND3_H

#include "command.h"
#include "knn.h"

class Command3: public Command{
private:
    DefaultIO* io_;
    varHolder& var;
public:
    Command3(DefaultIO* io, varHolder& variables);
    void execute();
};

#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_COMMAND3_H
