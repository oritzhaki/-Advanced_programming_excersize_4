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
    string saveData(string dataType) {return "";};
    string readFile(const string& filePath) {return "";};
    int writeFromFile(const string& data) {return 0;};
};


