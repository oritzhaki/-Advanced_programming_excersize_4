#include "command5.h"

Command5::Command5(DefaultIO dio, varHolder &variables) : Command("download results"){
    this->dio = dio;
    this->var = variables;
}

void Command5::execute() {
    // make sure to print result only after there has been valid classification
    if(this->var.getTrainDBR().is_empty() || this->var.getTestDBR().is_empty()){ // data check
        this->dio.write("please upload data");
    } else if(this->var.getClassifications().empty()){ // classification check
        this->dio.write("please classify the data");
    } else { // if got here - classifications info is available
        string out_classifications;
        string out_row;
        for(pair<int, string> c: this->var.getClassifications()){
            out_row = to_string(c.first) + "\t" + c.second + "\n";
            out_classifications = out_classifications + out_row;
        }
        this->dio.write("please enter path to save your results:\n"); // check if to add this output
        string path = this->dio.read();
        this->dio.writeFile(path, out_classifications);

    }
}