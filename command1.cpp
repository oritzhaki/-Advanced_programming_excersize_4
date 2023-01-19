#include "command1.h"

Command1::Command1(DefaultIO* io, varHolder& variables): Command("upload an unclassified csv data file"), io_(io), var(variables) {
    this->io_ = io;
    var.setK(5);
}

void Command1::execute() {
    try{
        // try read file and initialize reader train set
        this->io_->write("Please upload your local train CSV file.");
        string path1 = io_->read();
        this->var.setTrainDBR(path1);
        this->io_->write("Upload complete.\n");

        // try read file and initialize test set
        io_->write("Please upload your local test CSV file.");
        string path2 = this->io_->read();
        this->var.setTestDBR(path2);
        this->io_->write("Upload complete.\n");

        //clear previous classifications if exist:
        this->var.setClassifications({});
    } catch(...) {
        this->io_->write("invalid input.\n"); // path is invalid
        return;
    }
}
