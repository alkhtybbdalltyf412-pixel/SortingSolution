#include "shaker_sort.h"
#include <utility>

template <typename T>
void shaker_sort(T* arr, std::size_t n) {
    if (n < 2) return;

    std::size_t left = 0;
    std::size_t right = n - 1;
    bool swapped = true;

    while (swapped&& left < right) {
        swapped = false;

        for (std::size_t i = left; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        --right;

        if (!swapped) break;
        swapped = false;

        for (std::size_t i = right; i > left; --i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
        ++left;
    }
}

template void shaker_sort<int>(int*, std::size_t);
template void shaker_sort<double>(double*, std::size_t);