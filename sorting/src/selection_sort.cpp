#include "selection_sort.h"
#include <utility>

template <typename T>
void selection_sort(T* arr, std::size_t n) {
    for (std::size_t i = 0; i + 1 < n; ++i) {
        std::size_t min_idx = i;
        for (std::size_t j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        if (min_idx != i) std::swap(arr[i], arr[min_idx]);
    }
}

template void selection_sort<int>(int*, std::size_t);
template void selection_sort<double>(double*, std::size_t);