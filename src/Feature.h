//
// Created by Katherine Ritchie on 3/9/18.
//

#ifndef NAIVEBAYES_FEATUREARR_H
#define NAIVEBAYES_FEATUREARR_H

#endif //NAIVEBAYES_FEATUREARR_H


#include <vector>
#include <string>
using namespace std;

class Feature {
public:
    Feature();
    Feature(string picture_string);

    Feature(int number);

    vector<vector<int> > img_feature_vector;
};