#include "command2.h"
Command2::Command2(DefaultIO dio, varHolder &variables) : Command("algorithm settings") {
    this->dio = dio;
}
void Command2::execute(){}
