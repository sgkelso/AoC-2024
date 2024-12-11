#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "stdio.h"
using namespace std;

int main() {
    // FILE* fp = fopen("example.txt", "r");
    // if (fp == nullptr) {
    //     cout << "error reading file" << endl;
    //     exit(0);
    // }
    int num;
    int safe = 0;
    string line;
    ifstream file("example.txt");
    vector<int> level;
    bool isSafe = false;
    while (getline(file, line)) {
        auto test = line.c_str();
        char k = test[0];
        while (scanf(test, "%d", &num) == 1) {
            level.push_back(num);
        }
        bool increasing = false;
        int previous;
        for (int i = 0; i < level.size(); i++) {
            if (i == 0) {
                break;
            }
            int diff = level.at(i) - previous;
            if (diff > 0 && increasing == false) {
                isSafe = false;
                break;
            }
            else if (diff < 0 && increasing == true) {
                isSafe = false;
                break;
            }
            else if (diff == 0) {
                isSafe = false;
            }
            if (abs(diff) <= 1 || abs(diff) >= 3) {
                isSafe = false;
            }
            previous = level.at(i);
        }
        if (isSafe == true) {
            safe++;
        }
        level.clear();
    }
    cout << safe << endl;
}