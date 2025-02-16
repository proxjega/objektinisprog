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


struct Student {
    std::string name;
    std::string surname;
    std::vector<int>marks;
    int examMark = 0;
    float median = 0;
    float vid = 0;
};
