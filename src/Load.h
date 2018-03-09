//
// Created by Katherine Ritchie on 3/8/18.
//

#ifndef NAIVEBAYES_LOAD_H
#define NAIVEBAYES_LOAD_H

#endif //NAIVEBAYES_LOAD_H



#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

vector<string> FileToString();
vector<int> FileToLabelVector(string filename);
vector<vector<vector<int>>> FileToImageVector(string filename);
vector<vector<int>> StringToFeatureArr(string picture_string);



//Use this class to accept an image and label file and produce a dictionary with an image as an input and label as a key

//use this class to accept an image txt file and create an array of images