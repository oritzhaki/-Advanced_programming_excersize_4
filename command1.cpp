#include "command1.h"
Command1::Command1(DefaultIO dio) : Command("upload an unclassified csv data file") {
    this->dio = dio;
}
void Command1::execute() {
    /// @brief upload csv file according to user input
    auto csvFileUpload = [](string type, DefaultIO& dio, auto& data) {
        dio.write("Please upload your local " + type + " CSV file.\n");
        string path = dio.read();
        data = dio.readFile(path);
        dio.write("Upload complete.\n");
        };
    
    try{
        // try read file and initialize reader train set
        csvFileUpload("train", this->dio, this->trainReader);
        // try read file and initialize test set
        csvFileUpload("test", this->dio, this->testReader);
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
