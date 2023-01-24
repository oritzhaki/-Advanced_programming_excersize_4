#include "command1.h"

Command1::Command1(DefaultIO* io, varHolder& variables): Command("upload an unclassified csv data file"), io_(io), var(variables) {
    this->io_ = io;
    var.setK(5);
}

string Command1::execute() {
    try{
        // try read file and initialize reader train set
        // then try read file and initialize test set
        this->io_->write("Please upload your local train CSV file.");
        string trainData = io_->saveData("train"); // create local server train data file
        this->var.setTrainDBR(trainData);
        this->io_->write("Upload complete.\nPlease upload your local test CSV file.");
        string testData = this->io_->saveData("test"); // create local server test data file
        this->var.setTestDBR(testData);
        //clear previous classifications if exist:
        this->var.setClassifications({});
    
        return "Upload complete.\n";

    } catch(...) {
        return "invalid input.\n"; // data is invalid
    }
}
