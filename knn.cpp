#include "knn.h"


// constructor
Knn::Knn(int k, string metric) : distanceby(metric) {
    numOfNeighbors = k;
}


// Knn will have a pointer to the data in the DataSet
void Knn::fit(vector<vector<double>> xtrain, vector<string> ytrain){
    // vector which holds all the vectors (features of sample) in data
    this->xTrain = xtrain;
    // vector which holds all the labels of samples in data
    this->yTrain = ytrain;

    // fit k to our data in case k is bigger than neighbors number
    if(this->yTrain.size() < this->numOfNeighbors) { // making k to be valid if k is too big
        this->numOfNeighbors = this->yTrain.size();
    }
}


string Knn::predict(vector<double> v1){
    vector<pair<double, string>> distanceFromV1; // will hold all distances from v1 with labels
    pair<double, string> distLabel; // pair of distance as first value label as ve second value

    auto iterLabels = this->yTrain.begin(); // get iterator for labels.

    // calculate distance from vector v1 (input) to all other vectors
    // save the results as keys in distanceFromV1 pair.
    // save as values the labels from yTrain
    for(vector<double> v2 : this->xTrain){
        distanceby.setVectors(v1, v2);
        distLabel.first = distanceby.getDistance();
        distLabel.second = *iterLabels;
        distanceFromV1.push_back(distLabel);
        ++iterLabels; // move pointer to next label in vector
    }

    // find k nearest neighbors
    sort(distanceFromV1.begin(), distanceFromV1.end());

    return this->mostCommonLabel(distanceFromV1);
}

string Knn::mostCommonLabel(vector<pair<double, string>> distanceFromV1){
    // find most common label (of k neighbors)
    map<string, int> labelsAppearance;

    for(int i = 0; i < this->numOfNeighbors; i++){
        auto label = labelsAppearance.find(distanceFromV1[i].second); // get label if exist

        if(label == labelsAppearance.end()) // make sure label isn't already in map
        {
            labelsAppearance.insert({distanceFromV1[i].second, 1});
        }
        else // update num of appearance of label in map
        {
            int numAppearance = label->second;
            labelsAppearance.at(distanceFromV1[i].second) = numAppearance + 1;
        }
    }

    // find most common label
    string mostCommonLabel = "";
    int maxCount = 0;

    // iterate map and get label which appeared most in map
    for (const auto& x : labelsAppearance) {
        // check if current label appeared more then the most common label so far
        if (x.second > maxCount) {
            maxCount = x.second; // update maxCount
            mostCommonLabel = x.first;
        }
    }
    return mostCommonLabel;
}
