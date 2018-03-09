//
// Created by Katherine Ritchie on 3/8/18.
//

#include "NaiveBayes.h"

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
#include "vector"
using namespace std;

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <streambuf>

#include <iostream>
#include <fstream>
#include <string>

int main ();

int main ()
{
    std::cout << "hello world" << std::endl;

    ofstream myfile;
    myfile.open ("/Users/Kate/Documents/GitHub/naivebayes-KatherineRitchie/data/");
    myfile << "Writing this to a file.\n";
    myfile.close();

    return 0;
}

vector<vector<double>> CreateProbabilityMap(int target_number, vector<vector<vector<int>>> images) {
    vector<vector<double>> return_val;

    return return_val;
}