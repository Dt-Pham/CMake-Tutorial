/* 
 * A simple program to calculate square root of a number
 */

#include <iostream>
#include <cmath>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " number." << std::endl;
        return 1;
    }
    
    // convert input to double
    const double input = atof(argv[1]);

    const double output = std::sqrt(input);
    std::cout << output << std::endl;

    return 0;
}