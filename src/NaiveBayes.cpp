//
// Created by Katherine Ritchie on 3/8/18.
//

#include "NaiveBayes.h"

using namespace std;

int main ();



//LOAD HEADER
using FeatureVector_t = vector<vector<bool>>;
vector<int> FileToLabelVector(string filename);
vector<string> FileToImageStrings(string filename);
FeatureVector_t ImageStringToFeatureVector(string image_string);
vector<FeatureVector_t> FileToFeatureVectorVector(string filename);

int main ()
{
    std::cout << "hello world" << std::endl;

    /*string filename = "test";

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
            labels.push_back((int) line[0]);
        }
        myfile.close();
    } else {
        cout << "Unable to open file";
    }*/

    vector<int> labels = FileToLabelVector("test");
    vector<string> images = FileToImageStrings("test");
    vector<FeatureVector_t> features = FileToFeatureVectorVector("test");

    return 0;
}


//-------------------------LOAD FILE––––––––––––––––––––––––––––––//

//this method will call the two directly above
//vector<FeatureVector_t> FileToFeatureVectorVector(string filename);

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
    FeatureVector_t feature_vector(28, vector<bool>(28, false));

    int curr_char_counter = 0;
    for (int row_idx; row_idx < feature_vector.size(); row_idx++) {
        for (int col_idx; col_idx < feature_vector[row_idx].size(); col_idx++) {
            if (image_string[curr_char_counter] == ' ') {
                feature_vector[row_idx][col_idx] = false;
            } else {
                feature_vector[row_idx][col_idx] = true;
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
    vector<FeatureVector_t> features;

    for (int i = 0; i < feature_strings.size(); i++) {
        features.push_back(ImageStringToFeatureVector(feature_strings[i]));
    }

    return features;
}
