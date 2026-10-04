#include <gtest/gtest.h>
#include <algorithm>
#include <cstdio>
#include <random>
#include <vector>
#include "file_helpers.h"
#include "one_phase_merge_sort.h"

static const std::string F = "op_test.bin";

TEST(OnePhaseMergeSort, EmptyFile) {
    write_binary<int>(F, {});
    one_phase_merge_sort<int>(F);
    EXPECT_TRUE(read_binary<int>(F).empty());
    std::remove(F.c_str());
}

TEST(OnePhaseMergeSort, SingleElement) {
    write_binary<int>(F, { 5 });
    one_phase_merge_sort<int>(F);
    EXPECT_EQ(read_binary<int>(F), std::vector<int>({ 5 }));
    std::remove(F.c_str());
}

TEST(OnePhaseMergeSort, AlreadySorted) {
    write_binary<int>(F, { 1, 2, 3, 4, 5 });
    one_phase_merge_sort<int>(F);
    EXPECT_EQ(read_binary<int>(F), std::vector<int>({ 1, 2, 3, 4, 5 }));
    std::remove(F.c_str());
}

TEST(OnePhaseMergeSort, ReverseOrder) {
    write_binary<int>(F, { 5, 4, 3, 2, 1 });
    one_phase_merge_sort<int>(F);
    EXPECT_EQ(read_binary<int>(F), std::vector<int>({ 1, 2, 3, 4, 5 }));
    std::remove(F.c_str());
}

TEST(OnePhaseMergeSort, DoubleWithDuplicates) {
    write_binary<double>(F, { 2.5, 1.1, 2.5, -3.0, 0.0 });
    one_phase_merge_sort<double>(F);
    EXPECT_EQ(read_binary<double>(F), std::vector<double>({ -3.0, 0.0, 1.1, 2.5, 2.5 }));
    std::remove(F.c_str());
}

TEST(OnePhaseMergeSort, RandomData) {
    std::mt19937 gen(7);
    std::uniform_int_distribution<int> dist(-1000, 1000);
    std::vector<int> v(1000);
    for (auto& x : v) x = dist(gen);
    write_binary<int>(F, v);
    one_phase_merge_sort<int>(F);
    std::sort(v.begin(), v.end());
    EXPECT_EQ(read_binary<int>(F), v);
    std::remove(F.c_str());
}

TEST(OnePhaseMergeSort, TempFilesRemoved) {
    write_binary<int>(F, { 3, 1, 2 });
    one_phase_merge_sort<int>(F);
    EXPECT_FALSE(file_exists(F + ".tmp1"));
    EXPECT_FALSE(file_exists(F + ".tmp2"));
    EXPECT_FALSE(file_exists(F + ".tmp3"));
    EXPECT_FALSE(file_exists(F + ".tmp4"));
    std::remove(F.c_str());
}