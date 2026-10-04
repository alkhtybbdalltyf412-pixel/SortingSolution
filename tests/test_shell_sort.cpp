#include <gtest/gtest.h>
#include <vector>
#include "shell_sort.h"

TEST(ShellSort, EmptyArray) {
    std::vector<int> v;
    shell_sort(v.data(), v.size());
    EXPECT_TRUE(v.empty());
}

TEST(ShellSort, SingleElement) {
    std::vector<int> v = { 5 };
    shell_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 5 }));
}

TEST(ShellSort, AlreadySorted) {
    std::vector<int> v = { 1, 2, 3, 4 };
    shell_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(ShellSort, ReverseOrder) {
    std::vector<int> v = { 4, 3, 2, 1 };
    shell_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<int>({ 1, 2, 3, 4 }));
}

TEST(ShellSort, DoubleWithDuplicates) {
    std::vector<double> v = { 2.5, 1.1, 2.5, -3.0 };
    shell_sort(v.data(), v.size());
    EXPECT_EQ(v, std::vector<double>({ -3.0, 1.1, 2.5, 2.5 }));
}