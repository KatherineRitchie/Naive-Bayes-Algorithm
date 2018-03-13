//
// Created by Katherine Ritchie on 3/8/18.
//


#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/NaiveBayes.h"
#include <string>
using namespace std;


TEST_CASE("testing compiling") {
    REQUIRE(1 == 1);
}

TEST_CASE("testing load functions") {
#include "../src/Feature.h"
    string nine_image_string = "                                                                                                                                                                                                                 ++###+                      ######+                    +######+                    ##+++##+                   +#+  +##+                   +##++###+                   +#######+                   +#######+                    +##+###                       ++##+                       +##+                        ###+                      +###+                       +##+                       +##+                       +##+                       +##+                        ##+                        +#+                         +#+                                             ";
    Feature nine_feature = Feature(nine_image_string);
    REQUIRE(1 == 1);
}

TEST_CASE("Automatic load test functions") {
#include "../src/NaiveBayes.h"
    vector<int> labels = NaiveBayes::FileToLabelVector("test");
    REQUIRE(labels.size() == 1000);

    vector<string> images = FileToImageStrings("test");
    REQUIRE(images.size() == 1000);

    vector<FeatureVector_t> features = FileToFeatureVectorVector("test");
    REQUIRE(features.size() == 1000);

    DigitProbabilityFeature_t my_fun_prob_feature = BuildProbabilityFeature(features);
    REQUIRE(my_fun_prob_feature[14][14] == 0.622000);

    //REQUIRE(my_fun_prob_features[0] > 0.0);


    for (auto digit : digit_probability_features) {
        for (auto row : my_fun_prob_feature) {
            for (auto col : row) {
                std::cout << to_string(col) << " ";
            }
            std::cout << "" << std::endl;
        }
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
    }
}

TEST_CASE("some tests??") {
#include "../src/Load.h"
    //vector<Feature> images_vector = Load::FileToFeatureVector("test");
    //REQUIRE(images_vector.size() == (int) 1000);
}