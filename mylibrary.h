#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <limits>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::ifstream;
using std::stringstream;
using std::left;
using std::setw;
using std::setprecision;
using std::fixed;

struct Student {
    std::string name;
    std::string surname;
    std::vector<int>marks;
    int examMark = 0;
    float median = 0;
    float vid = 0;
};
