#include "CLI.h"

CLI::CLI(DefaultIO* io): variables() {
    this->io_ = io;
    commands.insert({"1", new Command1(this->io_, variables)});
    commands.insert({"2", new Command2(this->io_, variables)});
    commands.insert({"3", new Command3(this->io_, variables)});
    commands.insert({"4", new Command4(this->io_, variables)});
    commands.insert({"5", new Command5(this->io_, variables)});
};

void CLI::start() {
    while (true) {
        // create menu
        string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
        for (pair<string,Command*> c : commands) {
            //make string to send
            menu = menu + c.first + ". " + c.second->getDescription() + "\n";
        }
        menu = menu + "8. exit\n";
        this->io_->write(menu); // print menu
        // get user choice - input
        string input = this->io_->read();
        // check which command does the user want to execute
        if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5") {
            Command* command = commands.at(input); // get the wanted command from map
            command->execute();
            continue; // after finish a command print menu again
        }
        else if (input == "8") {
            // need to close sockets and everything related
            // close connection to server
            for(pair<string,Command*> c : commands) {
                delete c.second; // this is how to delete all new?
            }
            commands.clear();
            return;
        }
        else {
            this->io_->write("invalid @@@ input\n");
        }
    }
};