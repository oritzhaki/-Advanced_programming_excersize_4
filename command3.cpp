#include "command3.h"

Command3::Command3(DefaultIO dio, varHolder &variables): Command("classify data") {
    this->dio = dio;
    this->var = variables;
}

void Command3::execute() {}
