#include "CLI.h"

CLI::CLI(DefaultIO* io): variables() {
    this->io_ = io;
    commands.insert({"1", new Command1(this->io_, variables)});
    commands.insert({"2", new Command2(this->io_, variables)});
    commands.insert({"3", new Command3(this->io_, variables)});
    commands.insert({"4", new Command4(this->io_, variables)});
    commands.insert({"5", new Command5(this->io_, variables)});
    // commands.insert({"8", new Command5(this->io_, variables)});
}

void CLI::start() {
    // create menu
    string menu = "\nWelcome to the KNN Classifier Server. Please choose an option:\n";
    for (pair<string,Command*> c : commands) {
        //make string to send
        menu = menu + c.first + ". " + c.second->getDescription() + "\n";
    }
    menu = menu + "8. exit\n";
    string tempmenu = menu;
    while (true) {
        this->io_->write(tempmenu); // print menu
        string input = this->io_->read(); // get user choice - input
        if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5") {
            //cout << "im in cli correct inputs" << endl;
            Command* command = commands.at(input); // get the wanted command from map
            string additional_string = command->execute();
            tempmenu = additional_string + menu;// after finish a command print menu again
        }
        else if (input == "8") {
            // close connection to server
            for(pair<string,Command*> c : commands) {
                delete c.second; // this is how to delete all new?
            }
            commands.clear();
            break;
        }
        else {
            tempmenu = "invalid input\n" + menu;
        }
    }
    return;
}