#include "histogram.h"
#include "svg.h"
#include <cassert>

void
test_positive()
{
    double BIN_HEIGHT=200;
    show_histogram_svg({2,5,3},BIN_HEIGHT);
    assert(BIN_HEIGHT == 200);
}
int main()
{
    test_positive();
    return 0;
}
