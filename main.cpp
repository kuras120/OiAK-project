#include <iostream>
#include <climits>

#include "src/include/library.h"

int main() {
    FloatingPoint floatingPoint({1}, {1});
    FloatingPoint floatingPoint1({1}, {1});

    std::cout << "FP + FP1" << std::endl;
    std::cout << floatingPoint;
    std::cout << floatingPoint1 << std::endl;

    FloatingPoint fp = floatingPoint + floatingPoint1;

    std::cout << fp;

    FloatingPoint floatingPoint2({5}, {-1});
    FloatingPoint floatingPoint3({3}, {-1});

    std::cout << "FP2 + FP3" << std::endl;
    std::cout << floatingPoint2;
    std::cout << floatingPoint3 << std::endl;

    FloatingPoint fp1 = floatingPoint2 + floatingPoint3;

    std::cout << fp1;

    FloatingPoint floatingPoint4({10}, {INT_MAX});
    FloatingPoint floatingPoint5({12}, {INT_MAX});

    std::cout << "FP4 + FP5" << std::endl;
    std::cout << floatingPoint4;
    std::cout << floatingPoint5 << std::endl;

    FloatingPoint fp2 = floatingPoint4 + floatingPoint5;

    std::cout << fp2;

    return 0;
}
