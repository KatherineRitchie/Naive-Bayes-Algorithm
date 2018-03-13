cmake_minimum_required(VERSION 3.5)
project(naivebayes)

set(CMAKE_CXX_STANDARD 14)

add_executable(naivebayes
        src/NaiveBayes.cpp
        src/NaiveBayes.h
        src/Load.h
        )

add_executable(testing
        tests/catch.hpp
        tests/NaiveBayesTests.cpp
        src/Load.h
        )