#include "optimized_bubble_sort.h"
#include <utility>

template <typename T>
void optimized_bubble_sort(T* arr, std::size_t n) {
    for (std::size_t i = 0; i + 1 < n; ++i) {
        bool swapped = false;
        for (std::size_t j = 0; j + 1 < n - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

template void optimized_bubble_sort<int>(int*, std::size_t);
template void optimized_bubble_sort<double>(double*, std::size_t);