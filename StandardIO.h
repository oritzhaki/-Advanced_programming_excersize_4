#include "DefaultIO.h"
#include <iostream>
#include <fstream>

using namespace std;

class StandardIO : DefaultIO {
public:
    StandardIO(){};
    string read();
    void write(const string& output);
    string readFile(const string& filePath);
    void writeFile(const string& filePath, const string& contents);
};


