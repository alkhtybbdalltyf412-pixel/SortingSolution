#include <gtest/gtest.h>
#include <vector>
#include "insertion_sort.h"

TEST(InsertionSort, EmptyArray) {
    std::vector<int> v;
    insertion_sort(v.data(), v.size());
    EXPECT_TRUE(v.empty());
}

TEST(InsertionSort, SingleElement) {
    std::vector<int> v = { 5 };
    insertion_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 5 }));
}

TEST(InsertionSort, AlreadySorted) {
    std::vector<int> v = { 1, 2, 3, 4 };
    insertion_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(InsertionSort, ReverseOrder) {
    std::vector<int> v = { 4, 3, 2, 1 };
    insertion_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(InsertionSort, DoubleWithDuplicates) {
    std::vector<double> v = { 2.5, 1.1, 2.5, -3.0 };
    insertion_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<double>({ -3.0, 1.1, 2.5, 2.5 }));
}