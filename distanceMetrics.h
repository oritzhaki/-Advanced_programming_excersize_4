#ifndef EXERCISE_3_DISTANCEMETRICS_H
#define EXERCISE_3_DISTANCEMETRICS_H

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int p = 2;

double Chebyshev(vector<double> v1, vector<double> v2);
double Canberra(vector<double> v1, vector<double> v2);
double Minkowski(vector<double> v1, vector<double> v2, int p);
vector<double> vectorAbsDifference(vector<double> v1, vector<double> v2);

#endif