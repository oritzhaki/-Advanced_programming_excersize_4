#include "command8.h"

Command8::Command8(DefaultIO* io, varHolder& variables): Command("exit"), io_(io), var(variables) {
    this->io_ = io;
}

string Command8::execute() {
    var.work = false;
    return "";
}