//
// Created by Katherine Ritchie on 3/9/18.
//

#ifndef NAIVEBAYES_PROBABILITYMAP_H
#define NAIVEBAYES_PROBABILITYMAP_H

#endif //NAIVEBAYES_PROBABILITYMAP_H

#include <vector>
#include <string>
#include "Feature.h"
using namespace std;

class ProbabilityMap {
public:
    ProbabilityMap();
    ProbabilityMap::ProbabilityMap(vector<Feature::Feature> features);

    vector<vector<double> > prob_feature_vector;
};