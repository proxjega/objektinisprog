#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::wcout;
using std::wstringstream;
using std::wstring;
using std::getline;

struct Student {
    std::wstring name;
    std::wstring surname;
    std::vector<int>marks;
    int examMark = 0;
    float median = 0;
    float vid = 0;
};