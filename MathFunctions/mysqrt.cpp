#include "MathFunctions.h"

// calculate square root using Babylonian method
// https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Babylonian_method
double mysqrt(double x) {
    double ans = x;
    for (int i = 0; i < 30; ++i) {
        ans = (ans + x / ans) / 2;
    }
    return ans;
}
