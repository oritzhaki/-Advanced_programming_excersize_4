#include "command5.h"

Command5::Command5(DefaultIO* io, varHolder& variables) : Command("download results"), io_(io), var(variables){
    this->io_ = io;
}

void Command5::execute() {
    // make sure to print result only after there has been valid classification
    if(this->var.getTrainDBR().is_empty() || this->var.getTestDBR().is_empty()){ // data check
        this->io_->write("please upload data");
    } else if(this->var.getClassifications().empty()){ // classification check
        this->io_->write("please classify the data");
    } else { // if got here - classifications info is available
        string out_classifications;
        string out_row;
        for(pair<int, string> c: this->var.getClassifications()){
            out_row = to_string(c.first) + "\t" + c.second + "\n";
            out_classifications = out_classifications + out_row;
        }
        this->io_->write("please enter path to save your results:\n"); // check if to add this output
        string path = this->io_->read();
        this->io_->writeFile(path, out_classifications);

    }
}