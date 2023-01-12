#include "distanceMetrics.h"
#include "distance.h"
using namespace std;


Distances::Distances(string metric){ // constructor
    distanceMetric = metric;
    vector<double> emptyv;
    v1 = emptyv;
    v2 = emptyv;
}


void Distances::setVectors(vector<double> vector1, vector<double> vector2){
    v1 = vector1;
    v2 = vector2;
}


double Distances::getDistance(){
    if(distanceMetric == "AUC") { // Euclidian distance
        return Minkowski(v1, v2, p);
    }
    else if (distanceMetric == "MAN") { // Manhattan distance
        return Minkowski(v1, v2, 1);
    }
    else if (distanceMetric == "MIN") { // Minkowski distance
        return Minkowski(v1, v2, 2);
    }
    else if (distanceMetric == "CHB") { //Chebyshev
        return Chebyshev(v1, v2);
    }
    else { //   if (distanceMetric == "CAN") -> Canberra
        return Canberra(v1, v2);
    }
}
