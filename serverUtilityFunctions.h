#ifndef EXERCISE_3_SERVERUTILITYFUNCTIONS_H
#define EXERCISE_3_SERVERUTILITYFUNCTIONS_H

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string tryClassification(string input, vector<vector<double>> xtrain, vector<string> ytrain);
vector<double> processFeatures(vector<string> stringV);
bool doubleValueCheck(const string& s);

#endif