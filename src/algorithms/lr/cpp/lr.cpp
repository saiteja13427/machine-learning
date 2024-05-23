#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "../../../../cppml/lr/lr.h"

using namespace std;

int main(){
    LR lr;
    vector<float> x, y;
    ifstream ifs;

    ifs.open("../../../data/placement.csv");
    string header;
    getline(ifs, header);

    double cgpa, package;

    string line;
    while(getline(ifs, line)){
        istringstream iss(line);
        string token;

        if(getline(iss, token, ',')) 
        {
            x.push_back(stod(token));
        }
        if(getline(iss, token, ',')){
            y.push_back(stod(token));
        }
    }

    lr.fit(x, y);
    std::cout << "Predicted package for 5.88 CGPA: " << lr.predict(5.88) << endl;;
}