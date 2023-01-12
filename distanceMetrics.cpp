#include "distanceMetrics.h"
#include "serverUtilityFunctions.h"


//calculates the Chebyshev distance
double Chebyshev(vector<double> v1, vector<double> v2){
    double distance=0;
    vector<double> differenceVector = vectorAbsDifference(v1, v2);
    return *max_element(differenceVector.begin(), differenceVector.end());
}

//calculates the Canberra distance
double Canberra(vector<double> v1, vector<double> v2){
    double distance=0;
    vector<double> differenceVector = vectorAbsDifference(v1, v2);
    for(int i=0; i<differenceVector.size(); i++){
        if (v1.at(i) != 0 && v2.at(i) != 0){ // lets not divide by 0
            distance += differenceVector.at(i) / (abs(v1.at(i)) + abs(v2.at(i)));
        }
    }
    return distance;
}

//calculates the Minkowski distance.
// p impacts how Minkowski distance behaves...
// p == 1 : like manhattan distance
// p == 2 : like euclidean distance
// p --> infinity : like chebyshev distance
double Minkowski(vector<double> v1, vector<double> v2, int p) {
    double distance=0;
    vector<double> differenceVector = vectorAbsDifference(v1, v2);
    int a = v1.size();
    for(int i=0; i<a; i++){
        distance += pow(differenceVector.at(i), p);
    }
    return pow(distance, 1.0/p);
}


// Func calculates the absolute difference between each element in the vectors, needed for distances
vector<double> vectorAbsDifference(vector<double> v1, vector<double> v2){
    vector<double> differenceVector;
    for(int i = 0; i<v1.size(); i++){
        differenceVector.push_back(abs(v1.at(i) - v2.at(i)));
    }
    return differenceVector;
}