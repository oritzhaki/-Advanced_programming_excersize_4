#include "CLI.h"

CLI::CLI() {
    Command1 cmd1();
    Command2 cmd2();
    Command3 cmd3();
    Command4 cmd4();
    Command5 cmd5();
    commands.insert({1, cmd1()});
    commands.insert({2, cmd2()});
    commands.insert({3, cmd3()});
    commands.insert({4, cmd4()});
    commands.insert({5, cmd5()});
}

void CLI::start() {
    ////////////////////////////////////
}