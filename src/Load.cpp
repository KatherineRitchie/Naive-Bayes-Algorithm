//
// Created by Katherine Ritchie on 3/8/18.
//

#include "Load.h"
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;


vector<vector<vector<int>>> FileToImageVector(string filename) {
    if (filename.compare("test") == 0) {
        filename = "/Users/Kate/Documents/GitHub/naivebayes-KatherineRitchie/data/testimages.txt";
    } else if (filename.compare("training") == 0) {
        filename = "/Users/Kate/Documents/GitHub/naivebayes-KatherineRitchie/data/trainingimages.txt";
    } else {
        std::cout << "Thats not a valid Image Vector File" << std::endl;
    }
    vector<vector<vector<int>>> images;

    //the following code was taken from an adapted from cpluplus.com
    ifstream myfile(filename);
    if (myfile.is_open()) {
        string feature_string = "";
        int i = 0;
        string line;
        while (getline(myfile,line)) {
            feature_string += line;
            i++;
            if (i >= 28) {
                images.std::push_back(StringToFeatureArr(feature_string));
                feature_string = "";
                i = 0;
            }
        }
        if (i != 0) {
            std::cout << "the image file passed doesnt have a multiple of 28 lines" << std::endl
        }
        myfile.close();
    } else {
        cout << "Unable to open file";
    }
    return images;
}

vector<int> FileToLabelVector(string filename) {
    if (filename.compare("test") == 0) {
        filename = "/Users/Kate/Documents/GitHub/naivebayes-KatherineRitchie/data/testlabels.txt";
    } else if (filename.compare("training") == 0) {
        filename = "/Users/Kate/Documents/GitHub/naivebayes-KatherineRitchie/data/traininglabels.txt";
    } else {
        std::cout << "Thats not a valid Label File" << std::endl;
    }

    vector<int> labels;

    //the following code was taken from an adapted from cpluplus.com
    ifstream myfile(filename);
    if (myfile.is_open()) {
        string line;
        while (getline(myfile,line)) {
            labels.push_back((int) line[0]);
        }
        myfile.close();
    } else {
        cout << "Unable to open file";
    }

    return labels;
}

//cannot accept /n
