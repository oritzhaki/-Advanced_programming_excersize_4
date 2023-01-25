#include "command1.h"
#include <thread>
#include <pthread.h>
Command1::Command1(DefaultIO* io, varHolder& variables): Command("upload an unclassified csv data file"), io_(io), var(variables) {
    this->io_ = io;
    var.setK(5);
}

string Command1::execute() {
    try{
        string train = "trainSet.csv";
        string test = "testSet.csv";
        
         // try read file and initialize reader train set
        // then try read file and initialize test set
        this->io_->write("Please upload your local train CSV file.");
        this->io_->saveData(train); // create local server train data file
        this->var.setTrainDBR(train);
        this->io_->write("Upload complete.\nPlease upload your local test CSV file.");
        this->io_->saveData(test); // create local server test data file
        this->var.setTestDBR(test);
        
        //clear previous classifications if exist:
        this->var.setClassifications({});

        remove("trainSet.csv");
        remove("testSet.csv");

        return "Upload complete.\n";

       

    } catch(...) {
        remove("trainSet.csv");
        remove("testSet.csv");
        return "invalid input.\n"; // data is invalid
    }
}
