#include "CLI.h"

CLI::CLI(DefaultIO dio): variables() {
    this->dio = dio;
    Command1 cmd1(this->dio, variables);
    Command2 cmd2(this->dio, variables);
    Command3 cmd3(this->dio, variables);
    Command4 cmd4(this->dio, variables);
    Command5 cmd5(this->dio, variables);
    commands.insert({"1", cmd1});
    commands.insert({"2", cmd2});
    commands.insert({"3", cmd3});
    commands.insert({"4", cmd4});
    commands.insert({"5", cmd5});
}

void CLI::start() {

    while (true) {
        // create menu
        string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
        for (pair<string,Command> c : commands) {
            //make string to send
            menu = menu + c.first + ". " + c.second.getDescription() + "\n";
        }
        this->dio.write(menu); // print menu
        // get user choice - input
        string input = this->dio.read();
        // check which command does the user want to execute
        if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5") {
            Command command = commands.at(input); // get the wanted command from map
            command.execute();
            continue; // after finish a command print menu again
        }
        else if (input == "8") {
            // need to close sockets and everything related
            // close connection to server
            break;
        }
        else {
            this->dio.write("invalid input");
        }
        
    }
    
}