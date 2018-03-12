//
// Created by Katherine Ritchie on 3/9/18.
//

#include "ProbabilityModel.h"
#include "Load.h"
#include "Feature.h"
#include <vector>
#include <sstream>
using namespace std;

ProbabilityModel() = default {
}

ProbabilityModel(vector<Feature> features) {
    for (Feature feature : features) {
        feature.img_feature_vector;
    }
}

ProbabilityModel GenerateProbabilityMap(vector<Feature> features) {
    ProbabilityModel probability_model;

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
            probability_model.prob_feature_vector[row_idx][col_idx] = pixel_sum / size;
        }
    }

    return probability_model;
}

/**
 * Writes to model.txt the vector of probabilites.
 * @param probability_models A vector of ProbabilityModel from 0-9
 */
static bool ProbabilityModel::WriteProbabilityModel(vector<ProbabilityModel> probability_models) {
    string file_string = "";
    for (ProbabilityModel model : probability_models) {
        file_string += ProbabilityModelToString(model);
    }
    ofstream myfile;
    myfile.open("/Users/Kate/Documents/GitHub/naivebayes-KatherineRitchie/data/model.txt");
    myfile << file_string;
    myfile.close();
    return true;
}

/**
 * Reads model.txt and returns a vector of probability models
 * @return vector<ProbabilityModel> 0-9
 */
static vector<ProbabilityModel> ProbabilityModel::ReadProbabilityModel() {
    vector<ProbabilityModel> probability_models;
    //the following code was taken and adapted from cpluplus.com
    ifstream myfile("/Users/Kate/Documents/GitHub/naivebayes-KatherineRitchie/data/model.txt");
    if (myfile.is_open()) {
        string line;
        int i = 0;
        string string_probability_model;
        while (getline(myfile,line)) {
            string_probability_model += line;
            string_probability_model += "\n";
            if (i >= 28) {
                ProbabilityModel model = ProbabilityModel::StringToProbabilityModel(string_probability_model);
                probability_models.push_back(model);
                string_probability_model = "";
                i = 0;
            }
        }
        myfile.close();
    } else {
        std::cout << "Unable to open file";
    }
    return probability_models;
}

/**
 * Takes in a Probability Feature and converts it into a string, with a space between every double and a line break
 * between every 28th double.
 * @param probability_map
 * @return
 */
static string ProbabilityModel::ProbabilityModelToString(ProbabilityModel probability_model) {
    string file_string = "";
    for (int row_idx = 0; row_idx < 28; row_idx++) {
        for (int col_idx = 0; col_idx < 28; col_idx++) {
            file_string += std::to_string(probability_model.prob_feature_vector[row_idx][col_idx]);
            file_string += " ";
        }
        file_string += "\n";
    }
}

/**
 * Turns a string to a probability model.
 * @param probability_model_string
 * @return Probability Model
 */
static ProbabilityModel ProbabilityModel::StringToProbabilityModel(string probability_model_string) {
    //taken from http://www.martinbroadhurst.com/how-to-split-a-string-in-c.html
    std::stringstream ss(probability_model_string);
    std::string token;
    vector<vector<double>> new_prob_feature_vector;
    vector<double> new_feature_row;
    //TODO find out why it doesnt like std::getlind or token
    while (std::getline(ss, token, "\n")) {
        new_feature_row.push_back(std::atof(token));
        if (new_feature_row.size() >= 28) {
            new_prob_feature_vector.push_back(new_feature_row);
            new_feature_row.clear();
        }
    }
    ProbabilityModel probability_model;
    probability_model.prob_feature_vector = new_prob_feature_vector;
    return probability_model;
}