#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"

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


void cin_height(double &BIN_HEIGHT)
{
    cerr<<"BIN_HEIGHT:";
    cin>>BIN_HEIGHT;
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
    cin_height(BIN_HEIGHT);
    show_histogram_svg(bins,BIN_HEIGHT);
    return 0;
}


