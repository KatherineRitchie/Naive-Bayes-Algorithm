//
// Created by Katherine Ritchie on 3/9/18.
//

#ifndef NAIVEBAYES_FEATUREARR_H
#define NAIVEBAYES_FEATUREARR_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "Feature.h"
using namespace std;

class Feature {
public:
    Feature() = default;
    Feature(string picture_string);

    Feature(int number);

    vector<vector<int> > img_feature_vector;

    vector<string> FileToString();
    vector<int> FileToLabelVector(string filename);
    vector<Feature> FileToFeatureVector(string filename);
};

#endif //NAIVEBAYES_FEATUREARR_H