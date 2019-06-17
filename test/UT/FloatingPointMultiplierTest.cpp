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

    ASSERT_THAT(result.getExponent(), testing::ElementsAre(2));
    ASSERT_THAT(result.getMantissa(true), testing::ElementsAre(3221225472, INT32_MIN));
}