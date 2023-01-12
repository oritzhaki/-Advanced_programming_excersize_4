#include "serverUtilityFunctions.h"
#include "knn.h"


bool doubleValueCheck(const string& s) {
    istringstream iss(s);
    float f;
    iss >> noskipws >> f;
    return iss.eof() && !iss.fail();
}


vector<double> processFeatures(vector<string> stringV){ // converts string vector into features double vector
    vector<double> features; // holds features of one sample in double converted from rowTemp
    for (int i = 0; i < stringV.size(); i++) {
        string temp = stringV[i];
        if(temp[0] == '.') { // include features of type .1, .2 etc
            temp = '0' + temp;
        }
        double temp2 = stod(temp);
        if (doubleValueCheck(temp)) {
            features.push_back(temp2);
        } else {
            throw false;
        } // only add if the input is valid
    }
    return features;
}


string tryClassification(string input, vector<vector<double>> xtrain, vector<string> ytrain){  // input should be "vector distance k"
    string temp;
    vector<string> strInputV; // will hold input values
    string space = " ";
    while(!input.empty()) { // split input into a vector according to spaces
        temp = input.substr(0, input.find(space));
        strInputV.push_back(temp);
        input.erase(0, temp.size()+1);
    }

    string strK = strInputV.back(); // validate k
    strInputV.pop_back();
    int k = stoi(strK); // if k isn't an int it throws error
    if(k <= 0) { // make sure k is positive
        throw false;
    }

    string metric = strInputV.back(); // validate distance
    strInputV.pop_back();
    if((metric != "AUC") && (metric != "MAN") &&
       (metric != "CHB") && (metric != "CAN") && (metric != "MIN")){
        throw false;
    }

    vector<double> featuresV = processFeatures(strInputV); // validation + proccessing of vector
    if(featuresV.size() != xtrain[0].size()){ // if input vector is of wrong size
        throw false;
    }

    Knn knn(k, metric);
    knn.fit(xtrain, ytrain);
    return knn.predict(featuresV);
}
