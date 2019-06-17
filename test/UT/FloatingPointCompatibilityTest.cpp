//
// Created by wojciech on 16.06.19.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "library.h"

TEST(CompatibilityTest, 2Elements) {
FloatingPoint fp1 = FloatingPoint({-1}, {-1});
FloatingPoint fp2 = FloatingPoint({0, 2}, {1});
FloatingPoint result = fp1 + fp2;

EXPECT_EQ(result.getExponent().size(), 2);
}

TEST(CompatibilityTest, 4Elements) {
FloatingPoint fp1 = FloatingPoint({1}, {1});
FloatingPoint fp2 = FloatingPoint({0, 0, 0, 2}, {-1});
FloatingPoint result = fp1 + fp2;

EXPECT_EQ(result.getExponent().size(), 4);
}