#include "command5.h"

Command5::Command5(DefaultIO* io, varHolder& variables) : Command("download results"), io_(io), var(variables){
    this->io_ = io;
}

string Command5::execute() {
    // make sure to print result only after there has been valid classification
    if(this->var.getTrainDBR().is_empty() || this->var.getTestDBR().is_empty()){ // data check
        return "please upload data\n";
    } else if(this->var.getClassifications().empty()){ // classification check
        return "please classify the data\n";
    } else { // if got here - classifications info is available
        string out_classifications;
        string out_row;
        for(pair<int, string> c: this->var.getClassifications()){
            out_row = to_string(c.first) + "\t" + c.second + "\n";
            out_classifications = out_classifications + out_row;
        }
        this->io_->write("upload results:");
        // string ready = this->io_->read();
        // if (ready == "READY_TO_SAVE") {
        this->io_->write(out_classifications);
        // }
        // this->io_->read();
    }
    return "";
}