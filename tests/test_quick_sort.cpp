#include <gtest/gtest.h>
#include <vector>
#include "quick_sort.h"

TEST(QuickSort, EmptyArray) {
    std::vector<int> v;
    quick_sort(v.data(), v.size());
    EXPECT_TRUE(v.empty());
}

TEST(QuickSort, SingleElement) {
    std::vector<int> v = { 5 };
    quick_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 5 }));
}

TEST(QuickSort, AlreadySorted) {
    std::vector<int> v = { 1, 2, 3, 4 };
    quick_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(QuickSort, ReverseOrder) {
    std::vector<int> v = { 4, 3, 2, 1 };
    quick_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(QuickSort, DoubleWithDuplicates) {
    std::vector<double> v = { 2.5, 1.1, 2.5, -3.0 };
    quick_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<double>({ -3.0, 1.1, 2.5, 2.5 }));
}