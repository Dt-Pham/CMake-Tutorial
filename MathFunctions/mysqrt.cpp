#include "MathFunctions.h"
#include "Table.h"
#include <cmath>
#include <iostream>

double mysqrt(double x) {
    if (x <= 0) {
        return nan("");
    }

    // use look up table if the value is small
    if (x < 10) {
        std::cout << "Use look up table" << std::endl;
        return sqrtTable[static_cast<int>(x)];
    }
    

#if defined(HAVE_LOG) && defined(HAVE_EXP)
    double ans = exp(log(x) * 0.5);
    std::cout << "Computing sqrt of " << x << " using log and exp" << std::endl;
    return ans;
#else
    // calculate square root using Babylonian method
    // https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Babylonian_method
    double ans = x;
    for (int i = 0; i < 30; ++i) {
        ans = (ans + x / ans) / 2;
    }
    std::cout << "Computing sqrt of " << x << " using Babylonian method" << std::endl;
    return ans;
#endif
}
