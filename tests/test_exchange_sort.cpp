#include <gtest/gtest.h>
#include <vector>
#include "exchange_sort.h"

TEST(ExchangeSort, EmptyArray) {
    std::vector<int> v;
    exchange_sort(v.data(), v.size());
    EXPECT_TRUE(v.empty());
}

TEST(ExchangeSort, SingleElement) {
    std::vector<int> v = { 5 };
    exchange_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 5 }));
}

TEST(ExchangeSort, AlreadySorted) {
    std::vector<int> v = { 1, 2, 3, 4 };
    exchange_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(ExchangeSort, ReverseOrder) {
    std::vector<int> v = { 4, 3, 2, 1 };
    exchange_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(ExchangeSort, DoubleWithDuplicates) {
    std::vector<double> v = { 2.5, 1.1, 2.5, -3.0 };
    exchange_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<double>({ -3.0, 1.1, 2.5, 2.5 }));
}