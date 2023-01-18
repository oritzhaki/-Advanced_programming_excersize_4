#include "command1.h"

Command1::Command1(DefaultIO dio, varHolder &variables) : Command("upload an unclassified csv data file") {
    this->dio = dio;
    this->var = variables;
}

void Command1::execute() {
    try{
        // try read file and initialize reader train set
        dio.write("Please upload your local train CSV file.\n");
        string path1 = dio.read();
        this->var.setTrainDBR(path1);
        dio.write("Upload complete.\n");

        // try read file and initialize test set
        dio.write("Please upload your local test CSV file.\n");
        string path2 = dio.read();
        this->var.setTestDBR(path2);
        dio.write("Upload complete.\n");

        //clear previous classifications if exist:
        this->var.setClassifications({});
    } catch(...) {
        return;
    }


////////////////////////////////////////////////////////////////////////////////
////////////// CHECK IF LAMDA WORKS. USE THE CODE BELOW IF IT DOESNT ///////////
////////////////////////////////////////////////////////////////////////////////

    // this->dio.write("Please upload your local train CSV file.\n");
    // string path = this->dio.read();
    // string fileContant = this->dio.readFile(path);
    // this->dio.write("Upload complete.\n");
    // this->dio.write("Please upload your local test CSV file.\n");
    // string path = this->dio.read();
    // string fileContant = this->dio.readFile(path);
    // this->dio.write("Upload complete.\n");
}
