#include "command2.h"

Command2::Command2(DefaultIO* io, varHolder& variables): Command("algorithm settings"), io_(io), var(variables) {
    this->io_ = io;
}

string Command2::execute(){
    string msg = "The current KNN parameters are: K = " + to_string(this->var.getK()) + ", distance metric = " + this->var.getMetric();
    this->io_->write(msg);
    string input = this->io_->read();
    cout << "cmd2 input: " << input << " .";
    if(!(input == "")){// the user entered "K MET"
        //break up the input
        vector<string> words;
        size_t start = 0, end = 0;
        while ((end = input.find(" ", start)) != string::npos) {
            words.push_back(input.substr(start, end - start));
            start = end + 1;
        }
        words.push_back(input.substr(start));

        //check validity:

        string k_invalid_msg = "invalid value for K\n";
        string met_invalid_msg = "invalid value for metric\n";
        bool k_valid = true;
        bool met_valid = true;
        string rtrn_message = "";

        //general validity:
        if(words.size() != 2){ // check correct order of inputs???
            return "invalid input.\n"; //////////////
        }

        // k validity:
        int new_k;
        try{
            new_k = stoi(words[0]); // if not number at all, here will already go to error
            if(!all_of(words[0].begin(), words[0].end(), ::isdigit)){throw false;} // check whole num
            if(new_k <= 0) {throw false;}// make sure k is positive
        } catch(...){
            rtrn_message = k_invalid_msg;
            k_valid = false;
        }

        //metric validity:
        string new_metric = words[1];
        if((new_metric != "AUC") && (new_metric != "MAN") &&
           (new_metric != "CHB") && (new_metric != "CAN") && (new_metric != "MIN")){
            rtrn_message = rtrn_message + met_invalid_msg;
            met_valid = false;
        }

        // update vals only if all is valid:
        if(k_valid && met_valid){
            this->var.setK(new_k);
            this->var.setMetric(new_metric);
        }
        return rtrn_message;
    }
    return ""; // if user pressed ENTER, will go straight to here
}
