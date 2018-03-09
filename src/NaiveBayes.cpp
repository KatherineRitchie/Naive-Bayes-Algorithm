//
// Created by Katherine Ritchie on 3/8/18.
//

#include "NaiveBayes.h"

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
using namespace std;

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <streambuf>

#include <iostream>
#include <fstream>
#include <string>
int main ();

int main ()
{
    std::cout << "hello world" << std::endl;

    string line;
    ifstream myfile("/Users/Kate/Documents/GitHub/naivebayes-KatherineRitchie/data/testimages.txt");
    //myfile.open("src/names.txt", std::ifstream::in);
    if (myfile.is_open())
    {
        while (getline(myfile,line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    return 0;
}