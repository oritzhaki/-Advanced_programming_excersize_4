#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_DefaultIO_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_DefaultIO_H

class DefaultIO {

public:
    DefaultIO(){};
    virtual string DefaultIO::read(){};
    virtual string DefaultIO::write(){};
    virtual string DefaultIO::readFile(){};
    virtual string DefaultIO::writeFile(){};
    
};

#endif