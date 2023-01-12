#ifndef EXERCISE_3_DISTANCE_H
#define EXERCISE_3_DISTANCE_H

#include <iostream>
#include <vector>

using namespace std;

class Distances{
private:
    string distanceMetric;
    vector<double> v1, v2;

public:
    Distances(string metric);
    void setVectors(vector<double> vector1, vector<double> vector2);
    double getDistance();
};

#endif