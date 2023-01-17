#ifndef ADVANCED_PROGRAMMING_EXERSIZE_4_VARHOLDER_H
#define ADVANCED_PROGRAMMING_EXERSIZE_4_VARHOLDER_H

#include <string>
#include "reader.h"

class varHolder {
private:
    int k;
    string metric;
    DBReader trainData;
    DBReader testData;
public:
    varHolder();
    int getK();
    void setK(int num);
    string getMetric();
    void setMetric(string newmetric);
    DBReader getTrainDBR();
    void setTrainDBR(string filepath);
    DBReader getTestDBR();
    void setTestDBR(string filepath);
};


#endif //ADVANCED_PROGRAMMING_EXERSIZE_4_VARHOLDER_H
