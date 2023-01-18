#include "command5.h"

Command5::Command5(DefaultIO dio, varHolder &variables) : Command("download results"){
    this->dio = dio;
    this->var = variables;
}

void Command5::execute() {}