#include <gtest/gtest.h>
#include <vector>
#include "selection_sort.h"

TEST(SelectionSort, EmptyArray) {
    std::vector<int> v;
    selection_sort(v.data(), v.size());
    EXPECT_TRUE(v.empty());
}

TEST(SelectionSort, SingleElement) {
    std::vector<int> v = { 5 };
    selection_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 5 }));
}

TEST(SelectionSort, AlreadySorted) {
    std::vector<int> v = { 1, 2, 3, 4 };
    selection_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(SelectionSort, ReverseOrder) {
    std::vector<int> v = { 4, 3, 2, 1 };
    selection_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(SelectionSort, DoubleWithDuplicates) {
    std::vector<double> v = { 2.5, 1.1, 2.5, -3.0 };
    selection_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<double>({ -3.0, 1.1, 2.5, 2.5 }));
}