#include "bubble_sort.h"
#include <utility>

template <typename T>
void bubble_sort(T* arr, std::size_t n) {
    for (std::size_t i = 0; i < n; ++i) {
        for (std::size_t j = 0; j + 1 < n; ++j) {
            if (arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);
        }
    }
}

template void bubble_sort<int>(int*, std::size_t);
template void bubble_sort<double>(double*, std::size_t);