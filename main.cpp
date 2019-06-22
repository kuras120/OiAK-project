#include <iostream>
#include <climits>
#include <chrono>
#include <bitset>
#include "src/include/library.h"

void measureTimeAdder() {
    std::cout << "Test 1 - 250k roznicy\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp1 = FloatingPoint({250001}, {1});
        FloatingPoint fp2 = FloatingPoint({1}, {1});
        FloatingPoint result1 = fp1 + fp2;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }

    std::cout << "Test 2 - 500k roznicy\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp1 = FloatingPoint({500001}, {1});
        FloatingPoint fp2 = FloatingPoint({1}, {1});
        FloatingPoint result1 = fp1 + fp2;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }

    std::cout << "Test 3 - 750k roznicy\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp3 = FloatingPoint({1, 750001}, {1, INT32_MIN});
        FloatingPoint fp4 = FloatingPoint({1, 1}, {1, INT32_MIN});
        FloatingPoint result2 = fp3 + fp4;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }

    std::cout << "Test 4 - 1m roznicy\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp5 = FloatingPoint({1, 1, 1000001}, {1, INT32_MIN, INT32_MIN});
        FloatingPoint fp6 = FloatingPoint({1, 1, 1}, {1, INT32_MIN, INT32_MIN});
        FloatingPoint result3 = fp5 + fp6;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }
}

void measureTimeAdder2() {
    std::cout << "Test 1 - 250k elementow\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp1 = FloatingPoint({2}, std::vector<int32_t>(250000, INT32_MIN));
        FloatingPoint fp2 = FloatingPoint({1}, std::vector<int32_t>(250000, INT32_MIN));
        FloatingPoint result1 = fp1 + fp2;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }

    std::cout << "Test 2 - 500k elementow\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp1 = FloatingPoint({2}, std::vector<int32_t>(500000, INT32_MIN));
        FloatingPoint fp2 = FloatingPoint({1}, std::vector<int32_t>(500000, INT32_MIN));
        FloatingPoint result1 = fp1 + fp2;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }

    std::cout << "Test 3 - 750k elementow\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp3 = FloatingPoint({1, 2}, std::vector<int32_t>(750000, INT32_MIN));
        FloatingPoint fp4 = FloatingPoint({1, 1}, std::vector<int32_t>(750000, INT32_MIN));
        FloatingPoint result2 = fp3 + fp4;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }

    std::cout << "Test 4 - 1m elementow\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp5 = FloatingPoint({1, 1, 2}, std::vector<int32_t>(1000000, INT32_MIN));
        FloatingPoint fp6 = FloatingPoint({1, 1, 1}, std::vector<int32_t>(1000000, INT32_MIN));
        FloatingPoint result3 = fp5 + fp6;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }
}

void measureTimeMultiplier() {
    std::cout << "Test 1 - 50k elementow\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp1 = FloatingPoint({16393}, std::vector<int32_t>(50000, INT32_MIN));
        FloatingPoint fp2 = FloatingPoint({1}, std::vector<int32_t>(50000, INT32_MIN));
        FloatingPoint result1 = fp1 * fp2;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }

    std::cout << "Test 2 - 100k elementow\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp1 = FloatingPoint({65536}, std::vector<int32_t>(100000, INT32_MIN));
        FloatingPoint fp2 = FloatingPoint({1}, std::vector<int32_t>(100000, INT32_MIN));
        FloatingPoint result1 = fp1 * fp2;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }

    std::cout << "Test 3 - 150k elementow\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp3 = FloatingPoint({1, 262144}, std::vector<int32_t>(150000, INT32_MIN));
        FloatingPoint fp4 = FloatingPoint({1, 1}, std::vector<int32_t>(150000, INT32_MIN));
        FloatingPoint result2 = fp3 * fp4;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }

    std::cout << "Test 4 - 200k elementow\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp5 = FloatingPoint({1, 1, 1048576}, std::vector<int32_t>(200000, INT32_MIN));
        FloatingPoint fp6 = FloatingPoint({1, 1, 1}, std::vector<int32_t>(200000, INT32_MIN));
        FloatingPoint result3 = fp5 * fp6;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }

    std::cout << "Test 4 - 250k elementow\n";
    for (int i = 0; i < 4; i ++) {
        auto start = std::chrono::high_resolution_clock::now();

        FloatingPoint fp5 = FloatingPoint({1, 1, 1048576}, std::vector<int32_t>(250000, INT32_MIN));
        FloatingPoint fp6 = FloatingPoint({1, 1, 1}, std::vector<int32_t>(250000, INT32_MIN));
        FloatingPoint result3 = fp5 * fp6;

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << elapsed.count() << "\n";
    }
}

int main() {
    FloatingPoint fp1 = FloatingPoint({1, 2}, {-1, INT32_MAX});
    FloatingPoint fp2 = FloatingPoint({1, 1}, {1, INT32_MAX});

    std::cout << "Elementy: \n";
    std::cout << fp1;
    std::cout << fp2;

    FloatingPoint result = fp1 + fp2;
    FloatingPoint result1 = fp1 - fp2;
    FloatingPoint result2 = fp1 * fp2;

    std::cout << "fp1 + fp2" << "\n";
    std::cout << result;
    std::cout << "fp1 - fp2" << "\n";
    std::cout << result1;
    std::cout << "fp1 * fp2" << "\n";
    std::cout << result2 << "\n";

    return 0;
}