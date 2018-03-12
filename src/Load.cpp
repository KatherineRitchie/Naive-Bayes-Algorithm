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


/*
vector<Feature_t> FileToFeatureTVector(string filename) {
    if (filename.compare("test") == 0) {
        filename = "/Users/Kate/Documents/GitHub/naivebayes-KatherineRitchie/data/testimages.txt";
    } else if (filename.compare("training") == 0) {
        filename = "/Users/Kate/Documents/GitHub/naivebayes-KatherineRitchie/data/trainingimages.txt";
    } else {
        std::cout << "Thats not a valid Image Vector File" << std::endl;
    }
    vector<Feature_t> features;

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
                features.std::push_back(StringToFeatureT(feature_string));
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
    return features;
}

vector<Feature_t> StringToFeatureTVector(string picture_string) {
    vector<Feature_t> return_val;
    return return_val;
}

Feature_t StringToFeatureT(string picture_string) {
    int pixels_in_feature_vector = 784;
    if ((int) picture_string.size != pixels_in_feature_vector) {
        std::cout << "this picture_string is the wrong length" << std::endl;
    }
    Feature_t feature_t;
    int pixel_idx = 0;
    for (int row_idx = 0; row_idx < 28; row_idx++) {
        for (int col_idx = 0; col_idx < 28; row_idx++) {
            bool pixel_val = true;
            if (picture_string.at(pixel_idx) == (char) " ") {
                pixel_val = false;
            }
            feature_t[row_idx][col_idx] = pixel_val;
        }
    }
    return feature_t;
}

Feature_t InitialiseFeatureT() {
    Feature_t feature_t;
    vector<vector<bool>> two_d_vector;
    for (int row_idx = 0; row_idx < 28; row_idx++) {
        vector<bool> new_row;
        for (int col_idx = 0; col_idx < 28; col_idx++) {
            new_row.push_back(false);
        }
        two_d_vector.push_back(new_row);
    }
    feature_t = two_d_vector;
    return feature_t;
}
*/
//cannot accept /n
