#include <iostream>
#include <climits>

#include "src/include/library.h"

int main() {
    FloatingPoint fp1 = FloatingPoint({1, 1024}, {1, 1});
    FloatingPoint fp2 = FloatingPoint({1, 1}, {2, 512});

    std::cout << "fp1 + fp2" << "\n";
    std::cout << fp1;
    std::cout << fp2;

    FloatingPoint result = fp1 + fp2;

    std::cout << result;

    return 0;
}
