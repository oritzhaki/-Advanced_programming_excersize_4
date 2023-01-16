#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_DefaultIO_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_DefaultIO_H

#include <iostream>
#include <string>

using namespace std;
class DefaultIO {

public:
    DefaultIO(){};
    virtual string DefaultIO::read(){}
    virtual string DefaultIO::write(string string){}
    virtual string DefaultIO::readFile(){}
    virtual string DefaultIO::writeFile(string string){}
    
};

#endif