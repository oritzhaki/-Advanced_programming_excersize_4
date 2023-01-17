#include "varHolder.h"

varHolder::varHolder(): trainData(true), testData(false){
    k = 5;
    metric = "AUC";
}

int varHolder::getK(){
    return this->k;
}

void varHolder::setK(int num){
    this->k = num;
}

string varHolder::getMetric(){
    return this->metric;
}

void varHolder::setMetric(string newmetric){
    this->metric = newmetric;
}

DBReader varHolder::getTrainDBR(){
    return this->trainData;
}

void varHolder::setTrainDBR(string filepath){
    this->trainData.clear();
    this->trainData.readerInit(filepath);
}

DBReader varHolder::getTestDBR(){
    return this->testData;
}

void varHolder::setTestDBR(string filepath){
    this->testData.clear();
    this->testData.readerInit(filepath);
}
