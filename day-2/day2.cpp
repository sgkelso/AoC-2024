#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "stdio.h"
#include <sstream>
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
    ifstream file("input.txt");
    vector<int> level;
    while (getline(file, line)) {
        bool isSafe = true;
        stringstream ss;
        int num = 0;
        ss << line;
        while (ss >> num) {
            level.push_back(num);
        }
        bool increasing = false;
        int previous;
        for (int i = 0; i < level.size(); i++) {
            if (i == 0) {
                previous = level.at(i);
                continue;
            }
            if(i == 1){
                increasing = ((level.at(i) - previous) > 0);
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
                break;
            }
            if (abs(diff) < 1 || abs(diff) > 3) {
                isSafe = false;
                break;
            }
            previous = level.at(i);
        }
        if (isSafe == true) {
            safe++;
        }
        // cout << line << endl;
        // cout << isSafe << endl << endl;
        level.clear();
    }
    cout << safe << endl;
}