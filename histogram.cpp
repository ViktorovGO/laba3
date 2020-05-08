#include "histogram.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
void find_minmax(const vector<double>& numbers,double &min,double &max)
{
    int q=numbers.size();
    if(q!=0)
    {
        min = numbers[0];
        max = numbers[0];
        for (double number : numbers)
        {
            if (number < min)
            {
                min = number;
            }
            if (number > max)
            {
                max = number;
            }
        }
    }
}

