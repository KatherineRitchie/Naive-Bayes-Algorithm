//
// Created by Katherine Ritchie on 3/9/18.
//

#ifndef NAIVEBAYES_PROBABILITYMAP_H
#define NAIVEBAYES_PROBABILITYMAP_H

#include <vector>
#include <string>
#include "Load.h"
using namespace std;
using DigitProbabilityFeatures_t = vector<vector<vector<double>>>;
DigitProbabilityFeatures_t features_for_class(10, vector<vector<double>>(28, vector<double>(28, 0.0))); // initializes a my_feature_vector for every possible class

bool BuildProbabilityModel(vector<FeatureVector_t> feature_vectors, vector<int> labels);
bool WriteProbabilityModel(DigitProbabilityFeatures_t features);
double ReadProbabilityModel(int digit, int row, int col);

/*
ProbabilityModel(vector<Feature> features);
static bool WriteProbabilityModel(vector<ProbabilityModel> probability_features);
static vector<ProbabilityModel> ReadProbabilityModel();
static string ProbabilityModelToString(ProbabilityModel probability_model);
static ProbabilityModel StringToProbabilityModel(string probability_model_string);
*/


#endif //NAIVEBAYES_PROBABILITYMAP_H
