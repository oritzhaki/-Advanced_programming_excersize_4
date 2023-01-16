#include "reader.h"


DBReader::DBReader(bool flag){
    myFile = "";
    line = "";
    word = "";
    yTrain = {};
    xTrain = {};
    is_classified = flag;
}

void DBReader::readerInit(string f){
    this->myFile = f;
    read();
}

// initiates xTrain and yTrain vectors by reading data from file
void DBReader::read() {
    if (this->is_classified) {
        vector<string> rowTemp;  // holds features of one sample in string from file
        rowTemp.clear();
        fstream fin(this->myFile, ios::in);
        size_t offset = 0;
        if (fin.is_open()) {
            do {
                rowTemp.clear();
                getline(fin, line);   // read an entire row and store it in a string variable 'line'
                stringstream s(line); // break the string up:
                while (getline(s, word, ',')) {
                    rowTemp.push_back(word);
                }
                this->yTrain.push_back(rowTemp.back()); // extract label and add to ytrain
                vector<double> features; // holds features of one sample in double converted from rowTemp
                // convert rowTemp string vector into features double vector
                for (int i = 0; i < rowTemp.size() - 1; i++) {
                    string temp = rowTemp[i];
                    if (temp[0] == '.') { // include features of type .1, .2 etc
                        temp = '0' + temp;
                    }
                    double temp2 = stod(temp, &offset);
                    if (this->dataCheck(temp, offset)) {
                        features.push_back(temp2);
                    } else {
                        throw 2;
                    } // only add if the input is valid
                }
                this->xTrain.push_back(features);
            } while (!fin.eof());

            int numofx = this->xTrain[0].size();// checking all vectors are the same size
            for (vector<double> v2 : this->xTrain) {
                if (v2.size() != numofx) {
                    throw 3;
                }
            }
        } else {
            throw 1;
        }
    } else { //read test set
        fstream fin(this->myFile, ios::in);
        vector<string> rowTemp;
        size_t offset = 0;
        if (fin.is_open()) {
            do {
                rowTemp.clear(); // wil hold the string values
                getline(fin, line);   // read an entire row and store it in a string variable 'line'
                stringstream s(line); // break the string up:
                while (getline(s, word, ',')) {
                    rowTemp.push_back(word);
                }
                vector<double> features; // holds features of one sample in double converted from rowTemp
                // convert rowTemp string vector into features double vector:
                for (int i = 0; i < rowTemp.size() - 1; i++) {
                    string temp = rowTemp[i];
                    if (temp[0] == '.') { // include features of type .1, .2 etc
                        temp = '0' + temp;
                    }
                    double temp2 = stod(temp, &offset);
                    if (this->dataCheck(temp, offset)) {
                        features.push_back(temp2);
                    } else {
                        throw 2;
                    } // only add if the input is valid
                }
                this->xTrain.push_back(features);
            } while (!fin.eof());
            this->yTrain = {};
        } else {
            throw 1;
        }
    }
}

vector<string> DBReader::getYtrain(){return this->yTrain;}

vector<vector<double>> DBReader::getXtrain(){return this->xTrain;}

bool DBReader::dataCheck(string temp, size_t offSet){
    // making sure input doesn't contain invalid characters that stod didn't catch
    if(temp.length() == offSet || isdigit(temp[offSet]) || temp[offSet] == 'E' || temp[offSet] == 'e'){
        // the first is to check perfect translation of the string, if this is false, then the string must be longer than
        // read from stod. If the second condition is true, then stod must have rounded the number (we will allow this).
        // We will also allow that E or e be included in the input because this is considered valid num. Now we need to
        // check that the rest of the input string is valid:
        if((temp[offSet] == 'E' && temp[offSet + 1] == '-') || (temp[offSet] == 'e' && temp[offSet + 1] == '-')){
            offSet += 2;
        }
        for(int i = offSet; i < temp.length(); i++){
            if(!isdigit(temp[offSet])){
                return false;
            }
        }
        return true;
    }
    return false;
}

bool DBReader::is_empty() {
    return this->xTrain.empty();
}
