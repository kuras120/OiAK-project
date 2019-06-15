//
// Created by wojci on 06.04.2019.
//

#ifndef FLOATINGPOINT_UTILS_H
#define FLOATINGPOINT_UTILS_H

class Utils {
public:
    static void mulBig(std::vector<uint32_t> &bigNum, uint16_t multiplicand);
    static void addBig(std::vector<uint32_t> &bigNum, uint16_t addend);
    static void atoBigNum(std::string str, std::vector<uint32_t> &bigNum);
    static std::vector<uint32_t> addVectors(const std::vector<uint32_t> &vectorOne, const std::vector<uint32_t> &vectorTwo);
    static std::vector<uint32_t> mulVectors(const std::vector<uint32_t> &vectorOne, const std::vector<uint32_t> &vectorTwo);
    static std::vector<uint32_t> divVectors(const std::vector<uint32_t> &vectorOne, const std::vector<uint32_t> &vectorTwo);

};
#endif //FLOATINGPOINT_UTILS_H