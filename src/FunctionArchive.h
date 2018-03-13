//
// Created by Katherine Ritchie on 3/12/18.
//

#ifndef NAIVEBAYES_FUNCTIONARCHIVE_H
#define NAIVEBAYES_FUNCTIONARCHIVE_H

#include "NaiveBayes.h"

/**
 * Modifies digit_probability_features global variable and puts in a probability feature corresponding to its index
 * @param feature_vectors All 28x28 bool grids
 * @param labels description of images in feature_vectors
 * @return boolean describing the success of the operation.
 */
bool BuildModelsFromFeatures(vector<FeatureVector_t> feature_vectors, vector<int> labels) {
    std::map<int, vector<FeatureVector_t >> features_for_digit_map;
    for (int i = 0; i < labels.size(); i++) {
        features_for_digit_map[labels[i]].push_back(feature_vectors[i]);
    }

    for (auto digit_element : features_for_digit_map) {
        digit_probability_features[digit_element.first] = BuildProbabilityFeature(digit_element.second);
    }

    return true;
}

#endif //NAIVEBAYES_FUNCTIONARCHIVE_H
