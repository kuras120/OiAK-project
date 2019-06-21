#include <utility>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <climits>
#include <bitset>
#include <math.h>

#include "Utils.h"

void Utils::mulBig(std::vector<uint32_t> &bigNum, uint16_t multiplicand) {
    uint32_t carry = 0;
    for (unsigned i = 0; i < bigNum.size(); i++) {
        uint64_t r = ((uint64_t )bigNum[i] * multiplicand) + carry;
        bigNum[i] = (uint32_t)(r&0xffffffff);
        carry = (uint32_t)(r >> 32);
    }
    if (carry) bigNum.push_back(carry);
}

void Utils::addBig(std::vector<uint32_t> &bigNum, uint16_t addend) {
    uint32_t carry = addend;

    for (unsigned i = 0; carry && i < bigNum.size(); i++) {
        uint64_t r = (uint64_t)bigNum[i] + carry;
        bigNum[i] = (uint32_t)(r&0xffffffff);
        carry = (uint32_t)(r >> 32);
    }

    if (carry) bigNum.push_back(carry);
}

void Utils::atoBigNum(std::string str, std::vector<uint32_t> &bigNum) {
    bigNum.clear();
    bigNum.push_back(0);
    for (int i = 0; i < str.size(); i++) {
        mulBig(bigNum, 10);
        addBig(bigNum, str[i] - '0');
    }
}

std::vector<uint32_t> Utils::addVectors(const std::vector<uint32_t> &vectorOne, const std::vector<uint32_t> &vectorTwo) {
    std::vector<uint32_t> vectorToReturn(vectorOne.size(), 0);

    uint32_t carry = 0;
    for(int i = 0; i < vectorOne.size(); i++){
        uint64_t add = (uint64_t) vectorOne[i] + (uint64_t) vectorTwo[i] + carry;
        vectorToReturn[i] = (uint32_t) (add & 0xffffffff);
        carry = (uint32_t) (add >> 32);
    }

    int16_t sign1 = (vectorOne.back() >> 31) & 1;
    int16_t sign2 = (vectorTwo.back() >> 31) & 1;
    int16_t signResult = (vectorToReturn.back() >> 31) & 1;

    if (sign1 + sign2 - (int16_t)carry != signResult) vectorToReturn.push_back(carry);

    return vectorToReturn;
}

std::vector<uint32_t> Utils::mulVectors(const std::vector<uint32_t> &vectorOne, const std::vector<uint32_t> &vectorTwo) {
    std::vector<uint32_t> vectorToReturn(vectorOne.size() * 2, 0);

    for (int i = 0; i < vectorOne.size(); i ++) {
        for (int j = 0; j < vectorTwo.size(); j ++) {
            uint64_t r;

            if (i == vectorOne.size() - 1 && j == vectorTwo.size() - 1) {
                r = (int64_t)(int32_t)vectorOne[j] * (int64_t)(int32_t)vectorTwo[i] + vectorToReturn[j + i];
            }
            else {
                r = (uint64_t)vectorOne[j] * (uint64_t)vectorTwo[i] + vectorToReturn[j + i];
            }
            vectorToReturn[j + i] = (uint32_t)(r&0xffffffff);
            vectorToReturn[j + i + 1] = (uint32_t)(r >> 32);
        }
    }

    while (((vectorToReturn.back() >> 31) & 1) == ((vectorToReturn[vectorToReturn.size() - 2] >> 31) & 1)) {
        if (vectorToReturn.back() == 0 || (int32_t)vectorToReturn.back() == -1) vectorToReturn.pop_back();
        else break;
    }

    int16_t sign1 = (vectorOne.back() >> 31) & 1;
    int16_t sign2 = (vectorTwo.back() >> 31) & 1;
    int16_t signResult = (vectorToReturn.back() >> 31) & 1;

    if ((sign1 ^ sign2) != signResult) vectorToReturn.push_back(-(sign1 ^ sign2));

    return vectorToReturn;
}

std::vector<uint32_t> Utils::divVectors(const std::vector<uint32_t> &vectorOne, const std::vector<uint32_t> &vectorTwo) {
    std::vector<uint32_t> vectorToReturn(vectorOne.size(), 0);

    return vectorToReturn;
}
