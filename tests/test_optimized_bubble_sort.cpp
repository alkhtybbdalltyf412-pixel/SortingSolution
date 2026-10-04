#include <gtest/gtest.h>
#include <vector>
#include "optimized_bubble_sort.h"

TEST(OptimizedBubbleSort, EmptyArray) {
    std::vector<int> v;
    optimized_bubble_sort(v.data(), v.size());
    EXPECT_TRUE(v.empty());
}

TEST(OptimizedBubbleSort, SingleElement) {
    std::vector<int> v = { 5 };
    optimized_bubble_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 5 }));
}

TEST(OptimizedBubbleSort, AlreadySorted) {
    std::vector<int> v = { 1, 2, 3, 4 };
    optimized_bubble_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(OptimizedBubbleSort, ReverseOrder) {
    std::vector<int> v = { 4, 3, 2, 1 };
    optimized_bubble_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(OptimizedBubbleSort, DoubleWithDuplicates) {
    std::vector<double> v = { 2.5, 1.1, 2.5, -3.0 };
    optimized_bubble_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<double>({ -3.0, 1.1, 2.5, 2.5 }));
}