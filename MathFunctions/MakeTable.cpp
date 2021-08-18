// A simple program that builds a sqrt table
#include <iostream>
#include <cmath>
#include <fstream>

int main(int argc, char** argv) {
    if (argc < 2) {
        return 1;
    }

    std::ofstream fout(argv[1]);
    if (fout.is_open()) {
        fout << "double sqrtTable[] = {" << std::endl;
        for (int i = 0; i < 10; ++i) {
            fout << sqrt(static_cast<double>(i)) << "," << std::endl;
        }
        // close table with a zero
        fout << "0};" << std::endl;
        fout.close();
        return 0;
    }
    
    return 1;
}

