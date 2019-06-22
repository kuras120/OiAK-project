//
// Created by wojciech on 16.06.19.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "library.h"

TEST(PerformanceTest, 512Diffrence) {
    FloatingPoint fp1 = FloatingPoint({513}, {1});
    FloatingPoint fp2 = FloatingPoint({1}, {1});
    FloatingPoint result = fp1 + fp2;

    ASSERT_EQ(result.getSign(), 0);
    ASSERT_THAT(result.getMantissa(true), testing::ElementsAre(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1));
    ASSERT_THAT(result.getExponent(true), testing::ElementsAre(1));
}

TEST(PerformanceTest, 2048Diffrence) {
    FloatingPoint fp1 = FloatingPoint({1, 2049}, {1, INT32_MIN});
    FloatingPoint fp2 = FloatingPoint({1, 1}, {1, INT32_MIN});
    FloatingPoint result = fp1 + fp2;

    ASSERT_EQ(result.getSign(), 0);
    ASSERT_THAT(result.getMantissa(true), testing::ElementsAre(3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 3));
    ASSERT_THAT(result.getExponent(true), testing::ElementsAre(1, 32));
}

//TEST(PerformanceTest, 8096Diffrence) {
//    FloatingPoint fp1 = FloatingPoint({1, 1, 8097}, {1, INT32_MIN, INT32_MIN});
//    FloatingPoint fp2 = FloatingPoint({1, 1, 1}, {1, INT32_MIN, INT32_MIN});
//    FloatingPoint result = fp1 + fp2;
//
//    ASSERT_EQ(result.getSign(), 0);
//    ASSERT_THAT(result.getMantissa(true), testing::ElementsAre(3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1));
//    ASSERT_THAT(result.getExponent(true), testing::ElementsAre(1, 1, 32));
//}
