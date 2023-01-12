#ifndef EXERCISE_3_KNN_H
#define EXERCISE_3_KNN_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "distance.h"

using namespace std;

class Knn {
private:
    int numOfNeighbors;
    vector<vector<double>> xTrain;
    vector<string> yTrain;
    Distances distanceby;

public:
    Knn(int k, string metric);
    void fit(vector<vector<double>> xtrain, vector<string> ytrain);
    string predict(vector<double> v1);
    string mostCommonLabel(vector<pair<double, string>> distanceFromV1);
};

#endif