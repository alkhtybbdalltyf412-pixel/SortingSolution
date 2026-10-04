#include <gtest/gtest.h>
#include <vector>
#include "binary_insertion_sort.h"

TEST(BinaryInsertionSort, EmptyArray) {
    std::vector<int> v;
    binary_insertion_sort(v.data(), v.size());
    EXPECT_TRUE(v.empty());
}

TEST(BinaryInsertionSort, SingleElement) {
    std::vector<int> v = { 5 };
    binary_insertion_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 5 }));
}

TEST(BinaryInsertionSort, AlreadySorted) {
    std::vector<int> v = { 1, 2, 3, 4 };
    binary_insertion_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(BinaryInsertionSort, ReverseOrder) {
    std::vector<int> v = { 4, 3, 2, 1 };
    binary_insertion_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(BinaryInsertionSort, DoubleWithDuplicates) {
    std::vector<double> v = { 2.5, 1.1, 2.5, -3.0 };
    binary_insertion_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<double>({ -3.0, 1.1, 2.5, 2.5 }));
}