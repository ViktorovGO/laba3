#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <vector>
#include <string>
using namespace std;
void find_minmax(const vector<double>& numbers,double &min,double &max);
vector<size_t> make_histogram(size_t count,const vector<double>& numbers);
#endif // HISTOGRAM_H_INCLUDED
