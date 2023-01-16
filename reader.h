#ifndef EXERCISE_3_READER_H
#define EXERCISE_3_READER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

class DBReader{
private:
    string myFile;
    vector<vector<double>> xTrain;
    vector<string> yTrain;
    string line, word;
    bool is_classified;

public:
    DBReader(bool flag);
    void read();
    void readerInit(string f);
    vector<string> getYtrain();
    vector<vector<double>> getXtrain();
    bool dataCheck(string temp, size_t offSet);
    bool is_empty();
};

#endif