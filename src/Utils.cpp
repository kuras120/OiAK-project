#include <utility>

//
// Created by wojci on 06.04.2019.
//
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
    std::vector<uint32_t> vectorToReturn;

    vectorToReturn.reserve(vectorOne.size());
    for(int i=0; i<vectorOne.size(); i++)
        vectorToReturn.push_back(0);

    uint32_t carry = 0;
    for(int i = 0; i < vectorOne.size(); i++){
        uint64_t add = (uint64_t) vectorOne[i] + (uint64_t) vectorTwo[i] + carry;
        vectorToReturn[i] = (uint32_t) (add & 0xffffffff);
        carry = (uint32_t) (add >> 32);
    }

    std::bitset<32> b1(vectorOne[vectorOne.size() - 1]);
    uint16_t sign1 = b1[31];
    std::bitset<32> b2(vectorTwo[vectorTwo.size() - 1]);
    uint16_t sign2 = b2[31];
    std::bitset<32> b3(vectorToReturn[vectorToReturn.size() - 1]);
    uint16_t sign3 = b3[31];
    if (sign1 == sign2 && sign1 != sign3) vectorToReturn.push_back(carry);
    return vectorToReturn;
}

std::vector<uint32_t> Utils::mulVectors(const std::vector<uint32_t> &vectorOne, const std::vector<uint32_t> &vectorTwo) {
    std::vector<uint32_t> vectorToReturn;

    vectorToReturn.reserve(vectorOne.size());
    for(int i=0; i<vectorOne.size(); i++)
        vectorToReturn.push_back(0);

    uint32_t carry = 0;
    for (unsigned i = 0; i < vectorOne.size(); i++) {
        uint64_t r = ((uint64_t )vectorOne[i] * (uint64_t)vectorTwo[i]) + carry;
        vectorToReturn[i] = (uint32_t)(r&0xffffffff);
        carry = (uint32_t)(r >> 32);
    }

    if (carry) vectorToReturn.push_back(carry);

    return vectorToReturn;
}

std::vector<uint32_t> Utils::divVectors(const std::vector<uint32_t> &vectorOne, const std::vector<uint32_t> &vectorTwo) {
    std::vector<uint32_t> vectorToReturn;

    vectorToReturn.reserve(vectorOne.size());
    for(int i=0; i<vectorOne.size(); i++)
        vectorToReturn.push_back(0);

    return vectorToReturn;
}