//
// Created by Kirill on 20.04.2023.
//

#include <gtest/gtest.h>
#include <vector>
#include "interface.h"

boost::mutex mutex;
boost::condition_variable condition;

// Tests for min_max() function
TEST(MinMaxTest, EmptyArray) {
  std::vector<int> vec = {};
  EXPECT_EQ(std::make_pair(0, 0), min_max(vec));
}

TEST(MinMaxTest, PositiveValues) {
  std::vector<int> vec = {3, 2, 5, 1, 4};
  EXPECT_EQ(std::make_pair(3, 2), min_max(vec));
}

TEST(MinMaxTest, NegativeValues) {
  std::vector<int> vec = {-3, -2, -5, -1, -4};
  EXPECT_EQ(std::make_pair(2, 3), min_max(vec));
}

// Tests for average() function
TEST(AverageTest, EmptyArray) {
  std::vector<int> vec = {};
  EXPECT_EQ(0, average(vec));
}

TEST(AverageTest, PositiveValues) {
  std::vector<int> vec = {3, 2, 5, 1, 4};
  EXPECT_EQ(3, average(vec));
}

TEST(AverageTest, NegativeValues) {
  std::vector<int> vec = {-3, -2, -5, -1, -4};
  EXPECT_EQ(-3, average(vec));
}

TEST(AverageTest, LargeValues) {
  std::vector<int> vec = {INT_MAX, INT_MAX, INT_MAX};
  EXPECT_EQ(INT_MAX, average(vec));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
