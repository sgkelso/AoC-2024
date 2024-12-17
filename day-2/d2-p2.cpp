#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "stdio.h"
#include <sstream>
using namespace std;

bool originalSafe(vector<int> level)
{
    bool isSafe = true;
    bool increasing = false;
    int previous;
    for (int i = 0; i < level.size(); i++)
    {
        if (i == 0)
        {
            previous = level.at(i);
            continue;
        }
        if (i == 1)
        {
            increasing = ((level.at(i) - previous) > 0);
        }
        int diff = level.at(i) - previous;
        if (diff > 0 && increasing == false)
        {
            isSafe = false;
            break;
        }
        else if (diff < 0 && increasing == true)
        {
            isSafe = false;
            break;
        }
        else if (diff == 0)
        {
            isSafe = false;
            break;
        }
        if (abs(diff) < 1 || abs(diff) > 3)
        {
            isSafe = false;
            break;
        }
        previous = level.at(i);
    }
    return isSafe;
}

int main()
{
    int num;
    int safe = 0;
    string line;
    ifstream file("edges.txt");
    vector<int> level;
    while (getline(file, line))
    {
        bool isSafe = true;
        stringstream ss;
        int num = 0;
        ss << line;
        while (ss >> num)
        {
            level.push_back(num);
        }
        bool increasing = false;
        int previous;
        bool orig_inc;
        for (int i = 0; i < level.size(); i++)
        {
            if (i == 0)
            {
                previous = level.at(i);
                continue;
            }
            if (i == 1)
            {
                orig_inc = ((level.at(i) - previous) > 0);
            }
            increasing = ((level.at(i) - previous) > 0);
            int diff = level.at(i) - previous;
            if (increasing != orig_inc)
            {
                if (i == 2)
                {
                    if (level.at(i) < level.at(i - 1) && level.at(i) > level.at(i - 2))
                    {
                        vector<int> copy = level;
                        copy.erase(next(copy.begin(), 0));
                        isSafe = originalSafe(copy);
                        break;
                    }
                    else if (level.at(i) > level.at(i - 1) && level.at(i) < level.at(i - 2))
                    {
                        vector<int> copy = level;
                        copy.erase(next(copy.begin(), i - 1));
                        isSafe = originalSafe(copy);
                        break;
                    }
                }

                if (level.at(i) > level.at(i - 1) && level.at(i) < level.at(i - 2))
                {
                    vector<int> copy = level;
                    copy.erase(next(copy.begin(), i - 2));
                    isSafe = originalSafe(copy);
                    break;
                }
                else if (level.at(i) < level.at(i - 1) && level.at(i) > level.at(i - 2))
                {
                    vector<int> copy = level;
                    copy.erase(next(copy.begin(), i - 1));
                    isSafe = originalSafe(copy);
                    break;
                }
                else
                {
                    vector<int> copy = level;
                    copy.erase(next(copy.begin(), i));
                    isSafe = originalSafe(copy);
                    break;
                }
                break;
            }
            // increasing values when trend is not increasing
            else if (diff > 0 && increasing == false)
            {
                vector<int> copy = level;
                copy.erase(next(copy.begin(), i));
                isSafe = originalSafe(copy);
                break;
            }
            // decreasing values when trend is increasing
            else if (diff < 0 && increasing == true)
            {
                vector<int> copy = level;
                copy.erase(next(copy.begin(), i));
                isSafe = originalSafe(copy);
                break;
            }
            // no change in values
            else if (diff == 0)
            {
                vector<int> copy = level;
                copy.erase(next(copy.begin(), i));
                isSafe = originalSafe(copy);
                break;
            }
            // diff OOB
            if (abs(diff) < 1 || abs(diff) > 3)
            {
                if (i == 1)
                {
                    vector<int> copy = level;
                    copy.erase(next(copy.begin(), 0));
                    isSafe = originalSafe(copy);
                    break;
                }
                vector<int> copy = level;
                copy.erase(next(copy.begin(), i));
                isSafe = originalSafe(copy);
                break;
            }
            previous = level.at(i);
        }
        if (isSafe == true)
        {
            safe++;
        }
        else
        {
            cout << line << endl;
            cout << isSafe << endl;
        }
        level.clear();
    }
    cout << safe << endl;
}