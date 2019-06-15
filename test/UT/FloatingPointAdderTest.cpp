//
// Created by wojciech on 15.06.19.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "library.h"

TEST(AdderTest, PositiveFP) {
    FloatingPoint fp1 = FloatingPoint({-1}, {-1});
    FloatingPoint fp2 = FloatingPoint({1}, {1});
    FloatingPoint result = fp1 + fp2;

    ASSERT_EQ(result.getSign(), 0);
    ASSERT_THAT(result.getMantissa(true), testing::ElementsAre(3));
    ASSERT_THAT(result.getExponent(true), testing::ElementsAre(-1));
}

TEST(AdderTest, NegativeFP) {
    FloatingPoint fp1 = FloatingPoint({-1}, {1});
    FloatingPoint fp2 = FloatingPoint({1}, {-1});
    FloatingPoint result = fp1 + fp2;

    ASSERT_EQ(result.getSign(), 1);
    ASSERT_THAT(result.getMantissa(true), testing::ElementsAre(UINT32_MAX - 2));
    ASSERT_THAT(result.getExponent(true), testing::ElementsAre(-1));
}

TEST(AdderHugeNumberTest, PositiveFP) {
    FloatingPoint fp1 = FloatingPoint({-1}, {1, -1});
    FloatingPoint fp2 = FloatingPoint({1}, {-1, 1});
    FloatingPoint result = fp1 + fp2;

    ASSERT_EQ(result.getSign(), 0);
    ASSERT_THAT(result.getMantissa(true), testing::ElementsAre());
    ASSERT_THAT(result.getExponent(true), testing::ElementsAre());
}
