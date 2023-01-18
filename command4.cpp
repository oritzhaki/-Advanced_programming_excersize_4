#include "command4.h"

Command4::Command4(DefaultIO dio, varHolder &variables): Command("display results") {
    this->dio = dio;
    this->var = variables;
}

void Command4::execute() {
    if(this->var.getTrainDBR().is_empty() || this->var.getTestDBR().is_empty()){
        this->dio.write("please upload data");
    } else if(this->var.getClassifications().empty()){
        this->dio.write("please classify the data");
    } else {
        string out_classifications;
        string out_row;
        for(pair<int, string> c: this->var.getClassifications()){
            out_row = to_string(c.first) + "\t" + c.second + "\n";
            out_classifications = out_classifications + out_row;
        }
        out_classifications = out_classifications + "Done.\n";
        this->dio.write(out_classifications);
    }
    return;
}