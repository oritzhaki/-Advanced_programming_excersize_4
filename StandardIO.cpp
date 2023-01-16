#include "StandardIO.h"


// Method to read input from the user
string StandardIO::read() {
    string input;
    getline(cin, input);
    return input;
}

// Method to write output to the user
void StandardIO::write(const string& output) {
    cout << output << endl;
}

// Method to read a file's contents and initial dbreader
DBReader StandardIO::readFile(const string& filePath) {
    DBReader newReader;
    try{ //check file validation
        newReader.readerInit(filePath);
        return newReader;
    } catch (...){
        // file doesnt exist/not valid OR bad value in file OR no consistant vector length
        this->write("invalid input\n");
        throw false;
    }

    // ifstream file(filePath);
    // if (!file.is_open()) {
    //     throw runtime_error("Error: Could not open file: " + filePath);
    // }
    // string contents((istreambuf_iterator<char>(file)),
    //                         istreambuf_iterator<char>());
    // return contents;
}

// Method to write a string to a file
void StandardIO::writeFile(const string& filePath, const string& contents) {
    ofstream file(filePath);
    if (!file.is_open()) {
        throw runtime_error("Error: Could not open file: " + filePath);
    }
    file << contents;
}




