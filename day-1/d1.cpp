#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "stdio.h"
using namespace std;


int main(){
    cout << "Starting read file" << endl;
    FILE *fp = fopen("day1.txt","r");
    if(fp == nullptr){
        cout << "error reading file" << endl;
        exit(0);
    }
    int one;
    int two;
    while(fp != EOF){
        scanf("%d %d", &one, &two);
    }
    vector<int> l1;
    vector<int> l2;

}