#include "command2.h"

Command2::Command2(DefaultIO* io, varHolder& variables): Command("algorithm settings"), io_(io), var(variables) {
    this->io_ = io;
}

bool isKValid(string k, int& newK) {
    try {
        newK = stoi(k); // if not number at all, here will already go to false
    } catch(...) {
        return false;
    }
    if(!all_of(k.begin(), k.end(), ::isdigit)){return false;} // check whole num
    if(newK <= 0) {return false;}// make sure k is positive

    // if we got here k is valid
    return true;

}

bool isMetricValid(string met, string& new_metric) {
    if ((met != "AUC") && (met != "MAN") &&
           (met != "CHB") && (met != "CAN") && (met != "MIN")) {
        return false;
    }
    // if we got here metric is valid
    new_metric = met;
    return true;
}

string Command2::execute(){
    string msg = "The current KNN parameters are: K = " + to_string(this->var.getK()) + ", distance metric = " + this->var.getMetric();
    this->io_->write(msg);
    string input;
    try {
        string input = this->io_->read();
    } catch(...) {
        return "";   // if user pressed ENTER, will go straight to here

    }
    cout << "cmd2 input: " << input << " .";
   
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
    int newK;
    if(!isKValid(words[0], newK) && !isKValid(words[1], newK)) {
        rtrn_message = k_invalid_msg;
        k_valid = false;
    }
        

    //metric validity:
    string new_metric;
    if(!isMetricValid(words[0], new_metric) && !isMetricValid(words[1], new_metric)) {
        rtrn_message = rtrn_message + met_invalid_msg;
        met_valid = false;
    }

    // update vals only if all is valid:
    if(k_valid && met_valid){
        this->var.setK(newK);
        this->var.setMetric(new_metric);
    }
    return rtrn_message;
    
}
