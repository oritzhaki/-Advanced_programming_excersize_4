#include "command3.h"
Command3::Command3(DefaultIO dio, varHolder &variables): Command("classify data") {
    this->dio = dio;
}
void Command3::execute() {}
