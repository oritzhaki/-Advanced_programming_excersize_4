#include "clientUtilityFunctions.h"


bool isValidNumber(const string& s) {
    istringstream iss(s);
    float f;
    iss >> noskipws >> f;
    return iss.eof() && !iss.fail();
}

// validate if input user is like: "vector distance k"
bool userInputValidation(string str) {
    try {
        if(str.length() == 0) { // make sure user insert input
            throw false;
        }

        string temp;
        vector<string> v; // will all splited strings of input 
        string space = " ";

        while(!str.empty()) { // split input into a vector according to spaces
            temp = str.substr(0, str.find(space)); 
            v.push_back(temp); 
            str.erase(0, temp.size()+1);
        }

        // check all vectors element
        // making sure input is valid
        

        // valid input should be -> vector distance k

        // validate k
        string strK = v.back(); 
        v.pop_back();
        int k = stoi(strK); // if k isn't an int it throws error
        if(k <= 0) { // make sure k is positive
            throw false; 
        }
        // validate distance
        string metric = v.back(); 
        v.pop_back();
        if((metric != "AUC") && (metric != "MAN") &&
            (metric != "CHB") && (metric != "CAN") && (metric != "MIN")){
            throw false;
        }

        // validate feature vector
        for (int i = 0; i < v.size(); i++) { 
            string temp = v[i];
            if(temp[0] == '.') { // include features of type .1, .2 etc
                temp = '0' + temp;
            }
            if(!isValidNumber(temp)) { 
                throw false;
            }
            
        }

        return true; // input is valid

    } catch(...) {
        cout << "invalid input" << endl;
        return false; // input is invalid
    }
}  
       