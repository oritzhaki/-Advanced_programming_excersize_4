#include "command4.h"

Command4::Command4(DefaultIO dio, varHolder &variables): Command("display results") {
    this->dio = dio;
    this->var = variables;
}

void Command4::execute() {}