#include "MathFunctions.h"
#include "Table.h"
#include <iostream>
#include <cmath>

namespace mathfunctions {
namespace detail {

double mysqrt(double x) {
    if (x <= 0) {
        return nan("");
    }

    double ans = x;
    // use look up table if the value is small
    if (x < 10) {
        std::cout << "Use look up table to find initial value" << std::endl;
        ans = sqrtTable[static_cast<int>(x)];
    }
    
    // calculate square root using Babylonian method
    // https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Babylonian_method
    for (int i = 0; i < 30; ++i) {
        ans = (ans + x / ans) / 2;
    }
    std::cout << "Computing sqrt of " << x << " using Babylonian method" << std::endl;
    return ans;
}

}
}
