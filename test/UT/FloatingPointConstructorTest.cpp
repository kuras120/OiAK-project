//
// Created by wojciech on 15.06.19.
//
#include <gtest/gtest.h>
#include "library.h"

TEST(MantissaSignTest, Positive) {
    FloatingPoint fp = FloatingPoint({0}, {1});
    EXPECT_EQ(0, fp.getSign());
    fp = FloatingPoint({0}, {INT32_MAX});
    EXPECT_EQ(0, fp.getSign());
    fp = FloatingPoint({0}, {0});
    EXPECT_EQ(0, fp.getSign());
    fp = FloatingPoint({0}, {INT32_MAX, -1});
    EXPECT_EQ(0, fp.getSign());
}

TEST(MantissaSignTest, Negative) {
    FloatingPoint fp = FloatingPoint({0}, {-1});
    EXPECT_EQ(1, fp.getSign());
    fp = FloatingPoint({0}, {(int32_t)(UINT32_MAX - INT32_MAX)});
    EXPECT_EQ(1, fp.getSign());
    fp = FloatingPoint({0}, {-1, INT32_MAX});
    EXPECT_EQ(1, fp.getSign());
    fp = FloatingPoint({0}, {(int32_t)(UINT32_MAX - INT32_MAX), 0});
    EXPECT_EQ(1, fp.getSign());
}

TEST(ExponentSignTest, Positive) {
    FloatingPoint fp = FloatingPoint({1}, {0});
    EXPECT_EQ(0, fp.getExponentSign());
    fp = FloatingPoint({INT32_MAX}, {0});
    EXPECT_EQ(0, fp.getExponentSign());
    fp = FloatingPoint({0}, {0});
    EXPECT_EQ(0, fp.getExponentSign());
    fp = FloatingPoint({INT32_MAX, -1}, {0});
    EXPECT_EQ(0, fp.getExponentSign());
}

TEST(ExponentSignTest, Negative) {
    FloatingPoint fp = FloatingPoint({-1}, {0});
    EXPECT_EQ(1, fp.getExponentSign());
    fp = FloatingPoint({(int32_t)(UINT32_MAX - INT32_MAX)}, {0});
    EXPECT_EQ(1, fp.getExponentSign());
    fp = FloatingPoint({-1, INT32_MAX}, {0});
    EXPECT_EQ(1, fp.getExponentSign());
    fp = FloatingPoint({(int32_t)(UINT32_MAX - INT32_MAX), 0}, {0});
    EXPECT_EQ(1, fp.getExponentSign());
}

