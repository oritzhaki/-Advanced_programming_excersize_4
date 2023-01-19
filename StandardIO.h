#include "DefaultIO.h"
#include <iostream>
#include <fstream>
using namespace std;

class StandardIO : public DefaultIO {
public:
    StandardIO(int num){};
    string read();
    void write(const string& output);
    void writeFile(const string& filePath, const string& contents);
};


