#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <windows.h>
using namespace std;
vector<double> input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
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

int main()
{   double BIN_HEIGHT=0;

    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;


    const auto bins =make_histogram(bin_count,numbers);

    show_histogram_svg(bins);

    return 0;
}


