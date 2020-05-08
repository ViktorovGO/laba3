#include "histogram.h"
#include "svg.h"
#include <cassert>

void
test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}
void
test_negat()
{
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}
void
test_equal()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 1, 1}, min, max);
    assert(min == 1);
    assert(max == 1);
}
void
test_1()
{
    double min = 0;
    double max = 0;
    find_minmax({1}, min, max);
    assert(min == 1);
    assert(max == 1);
}
void
test_void()
{
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}
void
test_var()
{
    double BIN_HEIGHT=200;
    show_histogram_svg({2,5,3},BIN_HEIGHT);
    assert(BIN_HEIGHT == 200);
}
void
test_max()
{
    double BIN_HEIGHT=1000;
    show_histogram_svg({2,5,3},BIN_HEIGHT);
    assert(BIN_HEIGHT == 233);
}



int
main()
{
    test_positive();
    test_negat();
    test_equal();
    test_1();
    test_void();
    test_var();
    test_max();
    return 0;
}
