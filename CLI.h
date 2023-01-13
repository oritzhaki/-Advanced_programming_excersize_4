#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_CLI_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_CLI_H

using namespace std;

#include "command1.h"
#include "command2.h"
#include "command3.h"
#include "command4.h"
#include "command5.h"
#include <map>

class CLI {
private:
    map<int,Command> commands;
public:
    CLI();
    void start();
};


#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_CLI_H
