#include <gtest/gtest.h>
#include <algorithm>
#include <cstdio>
#include <random>
#include <vector>
#include "file_helpers.h"
#include "two_phase_merge_sort.h"

static const std::string F = "tp_test.bin";

TEST(TwoPhaseMergeSort, EmptyFile) {
    write_binary<int>(F, {});
    two_phase_merge_sort<int>(F);
    EXPECT_TRUE(read_binary<int>(F).empty());
    std::remove(F.c_str());
}

TEST(TwoPhaseMergeSort, SingleElement) {
    write_binary<int>(F, { 5 });
    two_phase_merge_sort<int>(F);
    EXPECT_EQ(read_binary<int>(F), std::vector<int>({ 5 }));
    std::remove(F.c_str());
}

TEST(TwoPhaseMergeSort, AlreadySorted) {
    write_binary<int>(F, { 1, 2, 3, 4, 5 });
    two_phase_merge_sort<int>(F);
    EXPECT_EQ(read_binary<int>(F), std::vector<int>({ 1, 2, 3, 4, 5 }));
    std::remove(F.c_str());
}

TEST(TwoPhaseMergeSort, ReverseOrder) {
    write_binary<int>(F, { 5, 4, 3, 2, 1 });
    two_phase_merge_sort<int>(F);
    EXPECT_EQ(read_binary<int>(F), std::vector<int>({ 1, 2, 3, 4, 5 }));
    std::remove(F.c_str());
}

TEST(TwoPhaseMergeSort, DoubleWithDuplicates) {
    write_binary<double>(F, { 2.5, 1.1, 2.5, -3.0, 0.0 });
    two_phase_merge_sort<double>(F);
    EXPECT_EQ(read_binary<double>(F), std::vector<double>({ -3.0, 0.0, 1.1, 2.5, 2.5 }));
    std::remove(F.c_str());
}

TEST(TwoPhaseMergeSort, RandomData) {
    std::mt19937 gen(42);
    std::uniform_int_distribution<int> dist(-1000, 1000);
    std::vector<int> v(1000);
    for (auto& x : v) x = dist(gen);
    write_binary<int>(F, v);
    two_phase_merge_sort<int>(F);
    std::sort(v.begin(), v.end());
    EXPECT_EQ(read_binary<int>(F), v);
    std::remove(F.c_str());
}

TEST(TwoPhaseMergeSort, TempFilesRemoved) {
    write_binary<int>(F, { 3, 1, 2 });
    two_phase_merge_sort<int>(F);
    EXPECT_FALSE(file_exists(F + ".tmp_b"));
    EXPECT_FALSE(file_exists(F + ".tmp_c"));
    std::remove(F.c_str());
}