#include <gtest/gtest.h>
#include <vector>
#include "bubble_sort.h"

TEST(BubbleSort, EmptyArray) {
    std::vector<int> v;
    bubble_sort(v.data(), v.size());
    EXPECT_TRUE(v.empty());
}

TEST(BubbleSort, SingleElement) {
    std::vector<int> v = { 5 };
    bubble_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 5 }));
}

TEST(BubbleSort, AlreadySorted) {
    std::vector<int> v = { 1, 2, 3, 4 };
    bubble_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(BubbleSort, ReverseOrder) {
    std::vector<int> v = { 4, 3, 2, 1 };
    bubble_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(BubbleSort, DoubleWithDuplicates) {
    std::vector<double> v = { 2.5, 1.1, 2.5, -3.0 };
    bubble_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<double>({ -3.0, 1.1, 2.5, 2.5 }));
}