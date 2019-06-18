//
// Created by wojciech on 17.06.19.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "library.h"

TEST(MultiplierTest, PositiveFP) {
    FloatingPoint fp1 = FloatingPoint({1}, {INT32_MAX});
    FloatingPoint fp2 = FloatingPoint({1}, {INT32_MAX});

    FloatingPoint result = fp1 * fp2;

    ASSERT_THAT(result.getExponent(), testing::ElementsAre(2));
    ASSERT_THAT(result.getMantissa(true), testing::ElementsAre(1073741823, 1));
}

TEST(MultiplierTest, NegativeFP) {
    FloatingPoint fp1 = FloatingPoint({1}, {INT32_MIN});
    FloatingPoint fp2 = FloatingPoint({1}, {INT32_MAX});

    FloatingPoint result = fp1 * fp2;

    ASSERT_THAT(result.getExponent(true), testing::ElementsAre(33));
    ASSERT_THAT(result.getMantissa(true), testing::ElementsAre(2147483649));
}

TEST(MultiplierTest, MoreElements) {
    FloatingPoint fp1 = FloatingPoint({1, 5}, {-1, INT32_MAX});
    FloatingPoint fp2 = FloatingPoint({5, 3}, {INT32_MAX, -1});

    FloatingPoint result = fp1 * fp2;

    ASSERT_THAT(result.getExponent(true), testing::ElementsAre(6, 8));
    ASSERT_THAT(result.getMantissa(true), testing::ElementsAre(3221225472, 2147483648, 2147483649));
}

TEST(MultiplierTest, MoreElements2) {
    FloatingPoint fp1 = FloatingPoint({10, 6}, {INT32_MIN, INT32_MAX});
    FloatingPoint fp2 = FloatingPoint({20, 12}, {INT32_MAX, INT32_MIN});

    FloatingPoint result = fp1 * fp2;

    ASSERT_THAT(result.getExponent(true), testing::ElementsAre(30, 49));
    ASSERT_THAT(result.getMantissa(true), testing::ElementsAre(2147483649, 2147483646, 2147483649));
}