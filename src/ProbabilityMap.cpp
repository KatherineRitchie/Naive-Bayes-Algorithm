//
// Created by Katherine Ritchie on 3/9/18.
//

#include "ProbabilityMap.h"
#include "Load.h"
#include <Feature.h>
#include "vector"
using namespace std;

ProbabilityMap::ProbabilityMap() {
}

ProbabilityMap::ProbabilityMap(vector<Feature::Feature> features) {
    for (auto feature : features) {

        feature.img_feature_vector;
    }
}

ProbabilityMap::ProbabilityMap GenerateProbabilityMap(vector<Feature::Feature> features) {
    ProbabilityMap probability_map;

    //adding laplace smoothing
    features.push_back(Feature::Feature(1));
    features.push_back(Feature::Feature(0));

    double size = (double) features.size();
    for (int row_idx = 0; row_idx < 28; row_idx++) {
        for (int col_idx = 0; col_idx < 28; col_idx) {
            double pixel_sum;
            for (Feature feature : features) {
                //TODO why is there a red line underneath this???
                pixel_sum += (double) feature.img_feature_vector[row_idx][col_idx];
            }
            probability_map.prob_feature_vector[row_idx][col_idx] = pixel_sum / size;
        }
    }

    return probability_map;
}

static void WriteProbabilityMap(ProbabilityMap probability_map) {
}