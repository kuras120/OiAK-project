#include <iostream>
#include <climits>
#include <chrono>
#include "src/include/library.h"

void measureTime() {
    std::cout << "Test 1 - 16k roznicy\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp1 = FloatingPoint({16393}, {1});
        FloatingPoint fp2 = FloatingPoint({1}, {1});
        FloatingPoint result1 = fp1 + fp2;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }

    std::cout << "Test 2 - 65k roznicy\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp1 = FloatingPoint({65536}, {1});
        FloatingPoint fp2 = FloatingPoint({1}, {1});
        FloatingPoint result1 = fp1 + fp2;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }

    std::cout << "Test 3 - 260k roznicy\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp3 = FloatingPoint({1, 262144}, {1, INT32_MIN});
        FloatingPoint fp4 = FloatingPoint({1, 1}, {1, INT32_MIN});
        FloatingPoint result2 = fp3 + fp4;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }

    std::cout << "Test 4 - 1m roznicy\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp5 = FloatingPoint({1, 1, 1048576}, {1, INT32_MIN, INT32_MIN});
        FloatingPoint fp6 = FloatingPoint({1, 1, 1}, {1, INT32_MIN, INT32_MIN});
        FloatingPoint result3 = fp5 + fp6;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }
}

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

