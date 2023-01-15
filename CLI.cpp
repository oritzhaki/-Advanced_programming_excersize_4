#include "CLI.h"

CLI::CLI(DefaultIO dio) {
    this->dio = dio;
    Command1 cmd1(this->dio);
    Command2 cmd2(this->dio);
    Command3 cmd3(this->dio);
    Command4 cmd4(this->dio);
    Command5 cmd5(this->dio);
    commands.insert({1, cmd1});
    commands.insert({2, cmd2});
    commands.insert({3, cmd3});
    commands.insert({4, cmd4});
    commands.insert({5, cmd5});
}

void CLI::start() {

    while (true) {
        // print menu
        for (pair<int,Command> c : commands) {
            //make string to send
            string str = c.first + ". " + c.second.getDescription() + "\n";
            this->dio.write(str);
        }
        string input = this->dio.read();
        if (input == "1") {

        }
        else if (input == "2")
        {
            /* code */
        }
        else if (input == "3")
        {
            /* code */
        }
        else if (input == "4")
        {
            /* code */
        }
        else if (input == "5")
        {
            /* code */
        }
        else if (input == "8")
        {
            // need to close sockets and everything related
            // close connection to server
            break;
        }
        
        else {
            this->dio.write("invalid input");
        }
        
    }
    
}