/* 
 * A simple program to calculate square root of a number
 */
#include <iostream>
#include "TutorialConfig.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#else
#include <cmath>
#endif

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number." << std::endl;
        return 1;
    }
    
    // convert input to double
    const double input = std::stod(argv[1]);

#ifdef USE_MYMATH
    const double output = mysqrt(input);
    std::cout << "mysqrt(" << input << ") = " << output << std::endl;
#else
    const double output = std::sqrt(input);
    std::cout << "std::sqrt(" << input << ") = " << output << std::endl;
#endif


    return 0;
}
