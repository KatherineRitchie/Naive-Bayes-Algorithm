//
// Created by Katherine Ritchie on 3/9/18.
//

#include "Feature.h"
using namespace std;


Feature::Feature() = default {
}

/**
* Constructor accepts string 784 char string without line breaks and converts it into a Feature vector
* @param picture_string string must be 784 chars
*/
Feature::Feature(string picture_string) {
    int pixels_in_feature_vector = 784;
    if ((int) picture_string.size != pixels_in_feature_vector) {
        std::cout << "this picture_string is the wrong length" << std::endl;
    }
    int pixel_idx = 0;
    for (int row_idx = 0; row_idx < 28; row_idx++) {
        for (int col_idx = 0; col_idx < 28; row_idx++) {
            int pixel_val = 1;
            if (picture_string.at(pixel_idx) == (char) " ") {
                pixel_val = 0;
            }
            img_feature_vector[row_idx][col_idx] = pixel_val;
        }
    }
}

Feature::Feature(int number) {
    int pixel_idx = 0;
    for (int row_idx = 0; row_idx < 28; row_idx++) {
        for (int col_idx = 0; col_idx < 28; row_idx++) {
            img_feature_vector[row_idx][col_idx] = number;
        }
    }
}