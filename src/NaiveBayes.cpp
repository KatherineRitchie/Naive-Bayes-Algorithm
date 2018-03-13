//
// Created by Katherine Ritchie on 3/8/18.
//

#include "NaiveBayes.h"

using namespace std;
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>
#include <stdio.h>      /* printf */
#include <math.h>

int main ();



//LOAD HEADER
//using keyword recommended by Yash and Dillon and example code they provided was adapted.
using FeatureVector_t = vector<vector<bool>>;
vector<int> FileToLabelVector(string filename);
vector<string> FileToImageStrings(string filename);
FeatureVector_t ImageStringToFeatureVector(string image_string);
FeatureVector_t BoolToFeatureVector(bool boolean);
vector<FeatureVector_t> FileToFeatureVectorVector(string filename);


//PROBABILITY MODEL HEADER
using DigitProbabilityFeature_t = vector<vector<double>>;
vector<DigitProbabilityFeature_t> digit_probability_features(10, vector<vector<double>>(28, vector<double>(28, 0.0)));
DigitProbabilityFeature_t BuildProbabilityFeature(vector<FeatureVector_t> feature_vectors);
bool BuildModelsFromFeatures(vector<FeatureVector_t> feature_vectors, vector<int> labels);
bool WriteProbabilityModel(vector<DigitProbabilityFeature_t> features);
double ReadProbabilityModel(int digit, int row, int col);

//COMPARING HEADER
int WhatNumberIsThis(string image_string);
double MAPCalculator(int digit, FeatureVector_t image_feature);

int main ()
{
    std::cout << "hello world" << std::endl;

    /*vector<int> labels = FileToLabelVector("test");
    vector<string> images = FileToImageStrings("test");
    vector<FeatureVector_t> features = FileToFeatureVectorVector("test");

    DigitProbabilityFeature_t my_fun_prob_feature = BuildProbabilityFeature(features);
    BuildModelsFromFeatures(features, labels);
    WriteProbabilityModel(digit_probability_features);*/

    string nine_image_string = "                                                                                                                                                                                                                 ++###+                      ######+                    +######+                    ##+++##+                   +#+  +##+                   +##++###+                   +#######+                   +#######+                    +##+###                       ++##+                       +##+                        ###+                      +###+                       +##+                       +##+                       +##+                       +##+                        ##+                        +#+                         +#+                                             ";

    vector<int> labels = FileToLabelVector("test");
    vector<string> images = FileToImageStrings("test");
    vector<FeatureVector_t> features = FileToFeatureVectorVector("test");
    //DigitProbabilityFeature_t my_fun_prob_feature = BuildProbabilityFeature(features);

    /*for(int row = 0; row < 28; row++) {
        for (int col = 0; col < 28; col++) {
            std::cout << to_string(my_fun_prob_feature[row][col]) << " ";
        }
        std::cout << "\n";
    }*/

    BuildModelsFromFeatures(features, labels);
    WriteProbabilityModel(digit_probability_features);

    //std::cout << to_string(log(10.0)) << std::endl;
    //std::cout << to_string(WhatNumberIsThis(nine_image_string)) << std::endl;

    return 0;
}


//-------------------------LOAD-FILE––––––––––––––––––-----––––––––––––//

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
 * Creates a feature vector composed entirely of one boolean. Used for laplace smoothing.
 * @param boolean
 * @return feature vector
 */
FeatureVector_t BoolToFeatureVector(bool boolean) {
    FeatureVector_t feature_vector(28, vector<bool>(28, boolean));
    return feature_vector;
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

//----------------------PROBABILITY-MODEL-FILE-------------------------//

/**
 * Given a vector of FeatureVector_ts, this function generates a 28x28 grid of doubles representing how likely
 * an image of that specific digit will have a marking in each 'pixel'.
 * @param feature_vectors A vector of 28x28 grids with booleans describing if the pixel has a marking.
 * @return A 28x28 feature with probabilities of having a marking in that specific pixel.
 */
DigitProbabilityFeature_t BuildProbabilityFeature(vector<FeatureVector_t> feature_vectors) {
    //Adding laplace smoothing
    feature_vectors.push_back(BoolToFeatureVector(true));
    feature_vectors.push_back(BoolToFeatureVector(false));

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
        DigitProbabilityFeature_t digit_feature = BuildProbabilityFeature(digit_element.second);
        for (auto row : digit_feature) {
            for (auto col : row) {
                std::cout << to_string(col) << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        digit_probability_features[digit_element.first] = digit_feature;
    }
    return true;
}

/**
 * Writes to model.txt file space seperating each double. Represented feature maps of different digit images
 * @param features 10 features, representing 0 - 9
 * @return boolean describing the success of the opeartion.
 */
bool WriteProbabilityModel(vector<DigitProbabilityFeature_t> features) {
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

/**
 * Reads model.txt and returns probability value in the digit, row and colum
 * @param digit 0 - 9
 * @param row 0 - 27
 * @param col 0 - 27
 * @return double of probability of their being a 'marking' in the represented square.
 */
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

            //convert string to char array, call strtod
            char char_array[double_string.size() + 1];
            strcpy(char_array, double_string.c_str());
            return_double = strtod(char_array, nullptr);
        }
        model_file.close();
    } else {
        std::cout << "Unable to open file";
    }
    return return_double;
}

//---------------------COMPARING-FILE-------------------------------//

/**
 * uses model.txt to generate maximum a posterior value and then returns most likely digit
 * @param image_string 784 char string of '#', '+' and ' '.
 * @return int of the digit.
 */
int WhatNumberIsThis(string image_string) {
    vector<double> p_of_being_this_digit(10, 0.0);
    FeatureVector_t image_feature = ImageStringToFeatureVector(image_string);

    double min_map_thus_far = 1.0;
    int min_idx = -1;
    for (int i = 0; i < 10; i++) {
        double map_val =  MAPCalculator(i, image_feature);
        p_of_being_this_digit[i] = map_val;
        //std::cout << to_string(map_val) << std::endl;
        if (p_of_being_this_digit[i] < min_map_thus_far) {
            min_idx = i;
            min_map_thus_far = p_of_being_this_digit[i];
        }
    }
    return min_idx;
}

/**
 * Calculates maximum a posterior value of a feature vector as compared with models.txt
 * @param digit to compare to
 * @param image_feature FeatureVector_t
 * @return double describing the MAP value
 */
double MAPCalculator(int digit, FeatureVector_t image_feature) {
    double map_sum = 0.0;
    for (int row_idx = 0; row_idx < 28; row_idx++) {
        for (int col_idx = 0; col_idx < 28; col_idx++) {
            if (image_feature[row_idx][col_idx]) {
                double val = ReadProbabilityModel(digit, row_idx, col_idx);
                std::cout << to_string(val) << std::endl;
                std::cout << to_string(log(val)) << std::endl;
                map_sum += log(val);
            } else {
                map_sum += log(1 - ReadProbabilityModel(digit, row_idx, col_idx));
            }
        }
    }
    std::cout << "map sum is : " << to_string(map_sum) << std::endl;
    return map_sum;
}
