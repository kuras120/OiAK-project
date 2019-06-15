#include <utility>
#include <iostream>
#include <bitset>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cmath>

#include "library.h"
#include "Utils.h"

FloatingPoint::FloatingPoint(const std::vector<int32_t>& exponent, const std::vector<int32_t>& mantissa) {
    exponent_ = std::vector<uint32_t>(exponent.begin(), exponent.end());
    mantissa_ = std::vector<uint32_t>(mantissa.begin(), mantissa.end());

    std::reverse(exponent_.begin(), exponent_.end());
    std::reverse(mantissa_.begin(), mantissa_.end());
}

FloatingPoint operator+(const FloatingPoint &x, const FloatingPoint &y) {
    std::vector<FloatingPoint> newArgs = FloatingPoint::compatibility(x, y);

    std::vector<uint32_t> exponent;
    std::vector<uint32_t> mantissa;

    std::vector<uint32_t> rest = FloatingPoint::alignExponents(newArgs[0], newArgs[1]);

    newArgs = FloatingPoint::compatibility(newArgs[0], newArgs[1], true);

    exponent = newArgs[0].exponent_;

    mantissa = Utils::addVectors(newArgs[0].mantissa_, newArgs[1].mantissa_);


    if (!rest.empty()) {
        bool flag = false;
        for (int i = 0; i < rest.size(); i ++) {
            if (rest[i] != 0) flag = true;
        }
        if (flag) {
            FloatingPoint::shiftLeft(mantissa, rest);
            uint32_t subSize = exponent.size() - rest.size();
            for (int i = 0; i < subSize; i ++) {
                rest.push_back(0);
            }
            rest = FloatingPoint::negate(rest);

            exponent = Utils::addVectors(exponent, rest);
        }
    }

    while (mantissa[0] == 0) mantissa.erase(mantissa.begin());

    std::reverse(exponent.begin(), exponent.end());
    std::reverse(mantissa.begin(), mantissa.end());

    return FloatingPoint(std::vector<int32_t>(exponent.begin(), exponent.end()), std::vector<int32_t>(mantissa.begin(), mantissa.end()));
}

FloatingPoint operator-(const FloatingPoint &x, const FloatingPoint &y) {
    FloatingPoint newY = y;
    newY.mantissa_ = FloatingPoint::negate(newY.mantissa_);
    return x+y;
}

FloatingPoint operator*(const FloatingPoint &x, const FloatingPoint &y) {
    std::vector<FloatingPoint> newArgs = FloatingPoint::compatibility(x, y);

    std::vector<uint32_t> exponent(newArgs[0].exponent_.size(), 0);
    std::vector<uint32_t> mantissa(newArgs[0].mantissa_.size(), 0);

    exponent = Utils::addVectors(newArgs[0].exponent_, newArgs[1].exponent_);
    mantissa = Utils::mulVectors(newArgs[0].mantissa_, newArgs[1].mantissa_);

    std::reverse(mantissa.begin(), mantissa.end());
    std::reverse(exponent.begin(), exponent.begin());

    return FloatingPoint(std::vector<int32_t>(exponent.begin(), exponent.end()), std::vector<int32_t>(mantissa.begin(), mantissa.end()));
}

FloatingPoint operator/(const FloatingPoint &x, const FloatingPoint &y) {
    std::vector<FloatingPoint> newArgs = FloatingPoint::compatibility(x, y);

    std::vector<uint32_t> exponent(newArgs[0].exponent_.size(), 0);
    std::vector<uint32_t> mantissa(newArgs[0].mantissa_.size(), 0);

    newArgs[1].exponent_ = FloatingPoint::negate(newArgs[1].exponent_);
    exponent = Utils::addVectors(newArgs[0].exponent_, newArgs[1].exponent_);
    mantissa = Utils::divVectors(newArgs[0].mantissa_, newArgs[1].mantissa_);

    std::reverse(mantissa.begin(), mantissa.end());
    std::reverse(exponent.begin(), exponent.begin());

    return FloatingPoint(std::vector<int32_t>(exponent.begin(), exponent.end()), std::vector<int32_t>(mantissa.begin(), mantissa.end()));
}

bool FloatingPoint::operator==(const FloatingPoint &x) {
    for (int i = 0; i < exponent_.size(); i ++) {
        if (exponent_[i] != x.exponent_[i]) return false;
    }

    for (int i = 0; i < mantissa_.size(); i ++) {
        if (mantissa_[i] != x.mantissa_[i]) return false;
    }

    return true;
}

bool FloatingPoint::operator!=(const FloatingPoint &x) {
    for (int i = 0; i < exponent_.size(); i ++) {
        if (exponent_[i] != x.exponent_[i]) return true;
    }

    for (int i = 0; i < mantissa_.size(); i ++) {
        if (mantissa_[i] != x.mantissa_[i]) return true;
    }

    return false;
}

bool FloatingPoint::operator<(const FloatingPoint &x) {
    if(GetSign() != x.GetSign()){
        return GetSign();
    }

    for(int i=0; i < exponent_.size(); i++){
        if(exponent_[i] < x.exponent_[i])
            return !GetExponentSign();

        if(exponent_[i] > x.exponent_[i])
            return GetExponentSign();
    }

    for(int i=0; i < mantissa_.size(); i++) {
        if(mantissa_[i] < x.mantissa_[i])
            return !GetSign();

        if(mantissa_[i] > x.mantissa_[i])
            return GetSign();
    }

    return false;
}

bool FloatingPoint::operator>(const FloatingPoint &x)  {
    if(GetSign() != x.GetSign()){
        return !GetSign();
    }

    for(int i=0; i < exponent_.size(); i++){
        if(exponent_[i] < x.exponent_[i])
            return GetExponentSign();

        if(exponent_[i] > x.exponent_[i])
            return !GetExponentSign();
    }

    for(int i=0; i < mantissa_.size(); i++) {
        if(mantissa_[i] < x.mantissa_[i])
            return GetSign();

        if(mantissa_[i] > x.mantissa_[i])
            return !GetSign();
    }

    return false;
}

bool FloatingPoint::operator<=(const FloatingPoint &x) {
    return *this < x || *this == x;
}

bool FloatingPoint::operator>=(const FloatingPoint &x) {
    return *this > x || *this == x;
}

FloatingPoint FloatingPoint::operator+=(FloatingPoint &y) {
    return *this + y;
}

FloatingPoint FloatingPoint::operator-=(const FloatingPoint &y) {
    return *this - y;
}

FloatingPoint FloatingPoint::operator/=(const FloatingPoint &y) {
    return *this / y;
}

FloatingPoint FloatingPoint::operator*=(const FloatingPoint &y) {
    return *this * y;
}

std::ostream &operator<<(std::ostream &os, FloatingPoint const &floatingPoint) {
    for (auto it = floatingPoint.exponent_.rbegin(); it != floatingPoint.exponent_.rend(); it++) {
        std::bitset<32> b(*it);
        os << b.to_string() << " ";
    }
    os << " | ";
    for (auto it = floatingPoint.mantissa_.rbegin(); it != floatingPoint.mantissa_.rend(); it++) {
        std::bitset<32> b(*it);
        os << b.to_string() << " ";
    }
    return os << std::endl;
}

bool FloatingPoint::GetSign() const {
    return (mantissa_.back() >> 31 ) & 1;
}

bool FloatingPoint::GetExponentSign() const {
    return (exponent_.back() >> 31 ) & 1;
}

std::vector<FloatingPoint> FloatingPoint::compatibility(FloatingPoint x, FloatingPoint y, bool mantissaFlag) {
    int toPush = x.mantissa_.size() - y.mantissa_.size();
    toPush = abs(toPush);

    if (mantissaFlag) {
        if(x.mantissa_.size() > y.mantissa_.size()) {

            for(int i = 0; i < toPush; i++) {
                y.mantissa_.insert(y.mantissa_.begin(), 0);
            }
        }
        else if(x.mantissa_.size() < y.mantissa_.size()){
            for(int i = 0; i < toPush; i++) {
                x.mantissa_.insert(x.mantissa_.begin(), 0);
            }
        }
    }
    else {
        if(x.mantissa_.size() > y.mantissa_.size()) {

            for(int i = 0; i < toPush; i++) {
                if (y.GetSign())
                    y.mantissa_.push_back(UINT_MAX);
                else y.mantissa_.push_back(0);
            }
        }
        else if(x.mantissa_.size() < y.mantissa_.size()){
            for(int i = 0; i < toPush; i++) {
                if (x.GetSign())
                    x.mantissa_.push_back(UINT_MAX);
                else x.mantissa_.push_back(0);
            }
        }
    }


    toPush = x.exponent_.size() - y.exponent_.size();
    toPush = abs(toPush);

    if(x.exponent_.size() > y.exponent_.size()){

        for(int i = 0; i < toPush; i++) {
            if (y.GetExponentSign())
                y.exponent_.push_back(UINT_MAX);
            else y.exponent_.push_back(0);
        }

    } else if(x.exponent_.size() < y.exponent_.size()){
        for(int i = 0; i < toPush; i++) {
            if (x.GetExponentSign())
                x.exponent_.push_back(UINT_MAX);
            else x.exponent_.push_back(0);
        }
    }

    return {x, y};
}

std::vector<uint32_t> FloatingPoint::negate(std::vector<uint32_t> toNegate) {
    std::vector<uint32_t> temp = std::move(toNegate);

    for (unsigned int & it : temp)
        it = ~it;

    Utils::addBig(temp, 1);

    return temp;
}

std::vector<uint32_t> FloatingPoint::alignExponents(FloatingPoint &x, FloatingPoint &y) {
    std::vector<uint32_t> rest(x.exponent_.size(), 0);

    uint32_t size = rest.size();

    int first = -1;

    for(int i=0; i < size; i++){
        if(i == size - 1){
            if ((int32_t)x.exponent_[i] < (int32_t)y.exponent_[i])
                first = 0;
            if ((int32_t)x.exponent_[i] > (int32_t)y.exponent_[i])
                first = 1;
        } else {
            if (x.exponent_[i] < y.exponent_[i])
                first = 0;
            if (x.exponent_[i] > y.exponent_[i])
                first = 1;
        }
    }

    if (first == -1) return {0};

    FloatingPoint *firstOperand;
    FloatingPoint *secondOperand;

    if (first) {
        firstOperand = &x;
        secondOperand = &y;
    }
    else {
        firstOperand = &y;
        secondOperand = &x;
    }

    uint32_t r = 0;

    for (int i = 0; i < size - 1; i ++) {
        uint64_t sub = (uint64_t)firstOperand->exponent_[i] - (uint64_t)secondOperand->exponent_[i] - r;
        rest[i] = (uint32_t)(sub&0xffffffff);
        r = (uint32_t)(sub >> 32);
    }

    rest[rest.size() - 1] =
            firstOperand->exponent_[size - 1] -
            secondOperand->exponent_[size - 1] - abs((int32_t)r);

    uint32_t carry = 0;

    for (int i = 0; i < size - 1; i++) {
        uint64_t add = (uint64_t) secondOperand->exponent_[i] + (uint64_t) rest[i] + carry;
        secondOperand->exponent_[i] = (uint32_t) (add & 0xffffffff);
        carry = (uint32_t) (add >> 32);
    }

    secondOperand->exponent_[size - 1] =
            secondOperand->exponent_[size - 1] +
            rest[size - 1] + abs((int32_t)carry);


    return FloatingPoint::shiftRight(secondOperand->mantissa_, rest);
}

std::vector<uint32_t> FloatingPoint::shiftRight(std::vector<uint32_t> &vec, const std::vector<uint32_t> &rest) {
    bool equal = false;
    bool internalCounterFlag = false;
    uint32_t sizeMantissa = vec.size();
    std::vector<uint32_t> counter(rest.size(), 0);
    std::vector<uint32_t> internalCounter(rest.size(), 0);

    while (!equal) {
        std::bitset<32> firstBit(vec[0]);
        if (firstBit[0] == 1) {
            internalCounterFlag = true;
            vec.insert(vec.begin(), 0);
            sizeMantissa = vec.size();
        }

        std::bitset<32> lastBit(vec[sizeMantissa - 1]);
        uint16_t bit = lastBit[31];

        for (int i = sizeMantissa - 1; i >= 0; i --) {
            uint16_t nextBit = vec[i] & (1 << (0));
            vec[i] = vec[i] >> 1;
            vec[i] |= (bit << 31);
            bit = nextBit;
        }

        Utils::addBig(counter, 1);
        if (internalCounterFlag) Utils::addBig(internalCounter, 1);

        equal = true;
        for (int i = sizeMantissa - 1; i >= 0; i --) {
            if (rest[i] != counter[i]) {
                equal = false;
                break;
            }
        }
    }
    return internalCounter;
}

void FloatingPoint::shiftLeft(std::vector<uint32_t> &vec, const std::vector<uint32_t> &rest) {
    bool equal = false;
    uint32_t sizeMantissa = vec.size();
    std::vector<uint32_t> counter(rest.size(), 0);

    while (!equal) {
        uint16_t bit = 0;
        for (int i = 0; i < vec.size(); i ++) {
            std::bitset<32> checkLastBit(vec[i]);
            vec[i] = vec[i] << 1;
            vec[i] |= (bit << 0);
            bit = checkLastBit[31];
        }

        Utils::addBig(counter, 1);

        equal = true;
        for (int i = sizeMantissa - 1; i >= 0; i --) {
            if (rest[i] != counter[i]) {
                equal = false;
                break;
            }
        }
    }
}
