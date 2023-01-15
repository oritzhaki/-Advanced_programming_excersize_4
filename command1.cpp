#include "command1.h"
Command1::Command1(DefaultIO dio) : Command("upload an unclassified csv data file") {
    this->dio = dio;
}
void Command1::execute(){}
