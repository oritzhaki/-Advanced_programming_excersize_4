#include "command3.h"

Command3::Command3(DefaultIO* io, varHolder& variables): Command("classify data"), io_(io), var(variables){
    this->io_ = io;
}

void Command3::execute() {
    if(this->var.getTrainDBR().is_empty() || this->var.getTestDBR().is_empty()){
        this->io_->write("please upload data");
    } else{
        Knn knn(this->var.getK(), this->var.getMetric());
        knn.fit(this->var.getTrainDBR().getXtrain(), this->var.getTrainDBR().getYtrain());
        vector<pair<int, string>> classifications = {}; // will hold the classifications of each vector in the test data
        for(int i = 0; i < this->var.getTestDBR().getXtrain().size(); i++){
            classifications.push_back(make_pair(i + 1, knn.predict(this->var.getTestDBR().getXtrain().at(i))));
        }
        this->var.setClassifications(classifications);
        this->io_->write("classifying data complete");
    }
    return;
}
