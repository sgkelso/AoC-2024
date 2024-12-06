#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "stdio.h"
using namespace std;
bool comp (int i, int j) {return (i < j);}

int main(){
    
    FILE *fp = fopen("day1.txt","r");
    if(fp == nullptr){
        cout << "error reading file" << endl;
        exit(0);
    }
    vector<int> l1;
    vector<int> l2;
    int one;
    int two;
    //parse from input file
    while(fscanf(fp,"%d %d",&one,&two) == 2){
        l1.push_back(one);
        l2.push_back(two);
    }
    sort(l1.begin(),l1.end(), comp);
    sort(l2.begin(),l2.end(), comp);
    int similarity = 0;
    for(int i = 0; i < l1.size(); i++){
        int l1count = 0;
        for(int j = 0; j < l2.size(); j++){
            if(l1.at(i) == l2.at(j)){
                l1count++;
            }
        }
        similarity += l1count * l1.at(i);
    }
    cout << similarity << endl;
}