#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_DefaultIO_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_DefaultIO_H

#include <iostream>
#include <string>
#include "reader.h"

using namespace std;
class DefaultIO {
public:
    DefaultIO(){};
    virtual string read(){};
    virtual void write(const string& output){};
    virtual DBReader readFile(const string& filePath){};
    virtual void writeFile(const string& filePath, const string& contents){};
    
};

#endif