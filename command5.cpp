#include "command5.h"
Command5::Command5(DefaultIO dio, varHolder &variables) : Command("download results"){
    this->dio = dio;
}
void Command5::execute() {}