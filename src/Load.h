//
// Created by Katherine Ritchie on 3/8/18.
//

#ifndef NAIVEBAYES_LOAD_H
#define NAIVEBAYES_LOAD_H

#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
//#include "Feature.h"
using namespace std;
//using FeatureVector_t = vector<vector<bool>>;

vector<int> FileToLabelVector(string filename);
//vector<string> FileToImageStrings(string filename);

//declare this and fill it in and return it
//FeatureVector_t feature_vector(28, vector<bool>(28, false));
//FeatureVector_t ImageStringToFeatureVector(string image_string);

//this method will call the two directly above
//vector<FeatureVector_t> FileToFeatureVectorVector(string filename);











//typedef vector<vector<bool>> Feature_t;

/*vector<string> FileToString();
vector<int> FileToLabelVector(string filename);
vector<FeatureVector_t> FileToFeatureTVector(string filename);
vector<FeatureVector_t> StringToFeatureTVector(string picture_string);
FeatureVector_t StringToFeatureT(string picture_string);
features_for_class vector<FeatureVector_t>*/

//Use this class to accept an image and label file and produce a dictionary with an image as an input and label as a key

//use this class to accept an image txt file and create an array of images

#endif //NAIVEBAYES_LOAD_H
