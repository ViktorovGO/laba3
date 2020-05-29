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
vector<size_t> make_histogram(size_t count,const vector<double>& numbers)
{   double min=0;
    double max=0;
    find_minmax(numbers,min,max);
    vector<size_t> bins(count);
    for (double number : numbers) {
        size_t bin = (size_t)((number - min) / (max - min) * count);
        if (bin == count)
        {
            bin--;
        }
        bins[bin]++;
    }
    return bins;
}

