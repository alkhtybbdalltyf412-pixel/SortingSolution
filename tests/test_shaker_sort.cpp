#include <gtest/gtest.h>
#include <vector>
#include "shaker_sort.h"

TEST(ShakerSort, EmptyArray) {
    std::vector<int> v;
    shaker_sort(v.data(), v.size());
    EXPECT_TRUE(v.empty());
}

TEST(ShakerSort, SingleElement) {
    std::vector<int> v = { 5 };
    shaker_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 5 }));
}

TEST(ShakerSort, AlreadySorted) {
    std::vector<int> v = { 1, 2, 3, 4 };
    shaker_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(ShakerSort, ReverseOrder) {
    std::vector<int> v = { 4, 3, 2, 1 };
    shaker_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(ShakerSort, DoubleWithDuplicates) {
    std::vector<double> v = { 2.5, 1.1, 2.5, -3.0 };
    shaker_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<double>({ -3.0, 1.1, 2.5, 2.5 }));
}