//
// Created by Katherine Ritchie on 3/12/18.
//

#ifndef NAIVEBAYES_FUNCTIONARCHIVE_H
#define NAIVEBAYES_FUNCTIONARCHIVE_H

#include "NaiveBayes.h"



/**
 * Reads file and populates digit_probability_features.
 * @return boolean describing success of the operation
 */
/*bool BuildModelsFromFile() {
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
}*/

/**
 * This method takes a space seperated string of doubles and turns it into a vector of doubles.
 * @param input_string space seperated string
 * @return vector<double>
 */
/*vector<double> StringToDoubleVector(string input_string) {
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
}*/

#endif //NAIVEBAYES_FUNCTIONARCHIVE_H
