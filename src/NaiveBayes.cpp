//
// Created by Katherine Ritchie on 3/8/18.
//

#include "NaiveBayes.h"

using namespace std;
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>

int main ();



//LOAD HEADER
//using keyword recommended by Yash and Dillon and example code they provided was adapted.
using FeatureVector_t = vector<vector<bool>>;
vector<int> FileToLabelVector(string filename);
vector<string> FileToImageStrings(string filename);
FeatureVector_t ImageStringToFeatureVector(string image_string);
vector<FeatureVector_t> FileToFeatureVectorVector(string filename);


//PROBABILITY MODEL HEADER
using DigitProbabilityFeature_t = vector<vector<double>>;
vector<DigitProbabilityFeature_t> digit_probability_features(10, vector<vector<double>>(28, vector<double>(28, 0.0)));
DigitProbabilityFeature_t BuildProbabilityFeature(vector<FeatureVector_t> feature_vectors);
bool BuildModelsFromFeatures(vector<FeatureVector_t> feature_vectors, vector<int> labels);
vector<double> StringToDoubleVector(string input_string);


double ReadProbabilityModel(int digit, int row, int col);

int main ()
{
    std::cout << "hello world" << std::endl;

    vector<int> labels = FileToLabelVector("test");
    vector<string> images = FileToImageStrings("test");
    vector<FeatureVector_t> features = FileToFeatureVectorVector("test");

    DigitProbabilityFeature_t my_fun_prob_feature = BuildProbabilityFeature(features);
    BuildModelsFromFeatures(features, labels);

    std::cout << to_string(ReadProbabilityModel(0, 0, 3)) << std::endl;


    //TODO WHEN YOU GET BACK KATE!!!!! FIND A WAY TO SPLIT A 7840 long string of double, seperated by spaces into a vector of doubles that you could turn into digit_prob_features.

    return 0;
}


//-------------------------LOAD FILE––––––––––––––––––––––––––––––//

/**
 * This accepts the string "test" or "training" and generates a vector of ints corresponding to the file images.
 * @param filename "test" or "training"
 * @return vector<int> of labels for corresponding images
 */
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
            labels.push_back(stoi(line));
        }
        myfile.close();
    } else {
        cout << "Unable to open file";
    }

    return labels;
}

/**
 * This returns a vector of strings that are used to represent the image of the digit.
 * @param filename "test" or "training". Does NOT accept other parameters.
 * @return vector<string> represent the images. All \n have been removed.
 */
vector<string> FileToImageStrings(string filename) {
    if (filename.compare("test") == 0) {
        filename = "/Users/Kate/Documents/GitHub/naivebayes-KatherineRitchie/data/testimages.txt";
    } else if (filename.compare("training") == 0) {
        filename = "/Users/Kate/Documents/GitHub/naivebayes-KatherineRitchie/data/trainingimages.txt";
    } else {
        std::cout << "Thats not a valid image File" << std::endl;
    }

    vector<string> features;
    //the following code was taken from an adapted from cpluplus.com
    ifstream myfile(filename);
    if (myfile.is_open()) {
        string curr_feature = "";
        int i = 0;
        string line;
        while (getline(myfile,line)) {
            curr_feature += line;
            i++;
            if (i >= 28) {
                features.push_back(curr_feature);
                curr_feature = "";
                i = 0;
            }
        }
        if (i != 0) {
            std::cout << "the image file passed doesnt have a multiple of 28 lines" << std::endl;
        }
        myfile.close();
    } else {
        cout << "Unable to open file";
    }
    return features;
}

/**
 * Turns an image string into a FeatureVector_t.
 * @param image_string must be 784 chars of ascii art representing a drawing of a digit
 * @return a vector of vectors of booleans. True is a marking, false is blank.
 */
FeatureVector_t ImageStringToFeatureVector(string image_string) {
    FeatureVector_t feature_vector(28, vector<bool>(28, true));

    int curr_char_counter = 0;
    for (int row_idx = 0; row_idx < feature_vector.size(); row_idx++) {
        //std::cout<< "i am inside row loop" << std::endl;
        for (int col_idx = 0; col_idx < feature_vector[row_idx].size(); col_idx++) {
            //std::cout<< "i am inside col loop" << std::endl;
            //std::cout << "char counter is at: " + to_string(curr_char_counter) << std::endl;
            if (image_string.string::at(curr_char_counter) == ' ') {
                //std::cout << "" + image_string.string::at(curr_char_counter) << std::endl;
                feature_vector[row_idx][col_idx] = false;
            }
            curr_char_counter++;
        }
    }

    return  feature_vector;
}

/**
 * Builds a vector of features based on the filename specified.
 * @param filename should be "test" or "training"
 * @return vector<FeatureVector_t> from the .txt file specified.
 */
vector<FeatureVector_t> FileToFeatureVectorVector(string filename) {
    vector<string> feature_strings = FileToImageStrings(filename);
    std::cout << feature_strings[0] << std::endl;
    vector<FeatureVector_t> features;

    for (int i = 0; i < feature_strings.size(); i++) {
        features.push_back(ImageStringToFeatureVector(feature_strings[i]));
    }

    return features;
}

//----------------------PROBABILITY-MODEL-FILE---------------------//

bool BuildModelsFromFile();
bool WriteProbabilityModel(DigitProbabilityFeature_t features);

/**
 * Given a vector of FeatureVector_ts, this function generates a 28x28 grid of doubles representing how likely
 * an image of that specific digit will have a marking in each 'pixel'.
 * @param feature_vectors A vector of 28x28 grids with booleans describing if the pixel has a marking.
 * @return A 28x28 feature with probabilities of having a marking in that specific pixel.
 */
DigitProbabilityFeature_t BuildProbabilityFeature(vector<FeatureVector_t> feature_vectors) {
    DigitProbabilityFeature_t probability_feature(28, vector<double>(28, 0.0));
    int size = feature_vectors.size();

    for (int row_idx = 0; row_idx < 28; row_idx++) {
        for (int col_idx = 0; col_idx < 28; col_idx++) {
            int sum = 0;
            for (int vector_idx = 0; vector_idx < size; vector_idx++) {
                if (feature_vectors[vector_idx][row_idx][col_idx] == true) {
                    sum++;
                }
            }
            probability_feature[row_idx][col_idx] = (double) sum / (double) size;
        }
    }

    return probability_feature;
}



bool WriteProbabilityModel(DigitProbabilityFeature_t features) {
    string file_string = "";
    for (DigitProbabilityFeature_t prob_feature : digit_probability_features) {
        for (auto row : prob_feature) {
            for (auto col : row) {
                file_string += to_string(col);
                file_string += " ";
            }
            file_string += " ";
        }
        file_string += " ";
    }
    ofstream model_file;
    model_file.open("/Users/Kate/Documents/GitHub/naivebayes-KatherineRitchie/data/model.txt");
    model_file << file_string;
    model_file.close();
    return true;
}

double ReadProbabilityModel(int digit, int row, int col) {

    //Every digit has 28 by 28 doubles, 8 chars in a double plus a space seperating them.
    int chars_in_a_digit = 28 * 28 * (8 + 1);
    int chars_in_a_row = 28 * (8 + 1);
    int chars_in_a_column = (8 + 1);

    double return_double;
    //the following code was taken and adapted from cpluplus.com
    ifstream model_file("/Users/Kate/Documents/GitHub/naivebayes-KatherineRitchie/data/model.txt");
    if (model_file.is_open()) {
        string file_content_string;
        if (getline(model_file,file_content_string)) {
            int char_pos = (digit * chars_in_a_digit) + (row * chars_in_a_row) + (col * chars_in_a_column);
            string double_string = (file_content_string.substr(char_pos, char_pos + chars_in_a_column));
            vector<double> return_vector = StringToDoubleVector(double_string);
            return_double = return_vector[0];
            //get the thing
        }
        model_file.close();
    } else {
        std::cout << "Unable to open file";
    }
    return return_double;
}

/**
 * Reads file and populates digit_probability_features.
 * @return boolean describing success of the operation
 */
bool BuildModelsFromFile() {
    //the following code was taken and adapted from cpluplus.com
    ifstream model_file("/Users/Kate/Documents/GitHub/naivebayes-KatherineRitchie/data/model.txt");
    vector<double> oned_double_vector;
    if (model_file.is_open()) {
        string file_content_string;
        if (getline(model_file,file_content_string)) {
            oned_double_vector = StringToDoubleVector(file_content_string);
        }
        model_file.close();
    } else {
        std::cout << "Unable to open file";
    }

    int curr_double_vector_pos = 0;
    for (int digit_idx = 0; digit_idx < 10; digit_idx++) {
        for (int row_idx = 0; row_idx < 28; row_idx++) {
            for (int col_idx = 0; col_idx < 28; col_idx++) {
                digit_probability_features[col_idx][row_idx][col_idx] = oned_double_vector[curr_double_vector_pos++];
            }
        }
    }

    return true;
}

/**
 * This method takes a space seperated string of doubles and turns it into a vector of doubles.
 * @param input_string space seperated string
 * @return vector<double>
 */
vector<double> StringToDoubleVector(string input_string) {
    vector<double> double_vector;

    stringstream input_as_ss(input_string);
    string double_string;
    while (getline(input_as_ss, double_string, ' ')) {
        char char_array[double_string.size() + 1];
        //code inspired by https://www.geeksforgeeks.org/convert-string-char-array-cpp/
        strcpy(char_array, double_string.c_str());
        double_vector.push_back(strtod(char_array, nullptr));
    }

    return double_vector;
}


