#include "command4.h"

Command4::Command4(DefaultIO* io, varHolder& variables): Command("display results"), io_(io), var(variables){
    this->io_ = io;
}

void Command4::execute() {
    if(this->var.getTrainDBR().is_empty() || this->var.getTestDBR().is_empty()){
        this->io_->write("please upload data");
    } else if(this->var.getClassifications().empty()){
        this->io_->write("please classify the data");
    } else {
        string out_classifications;
        string out_row;
        for(pair<int, string> c: this->var.getClassifications()){
            out_row = to_string(c.first) + "\t" + c.second + "\n";
            out_classifications = out_classifications + out_row;
        }
        out_classifications = out_classifications + "Done.\n";
        this->io_->write(out_classifications);
    }
    return;
}