#include "exchange_sort.h"
#include <utility>

template <typename T>
void exchange_sort(T* arr, std::size_t n) {
    for (std::size_t i = 0; i + 1 < n; ++i) {
        for (std::size_t j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) std::swap(arr[i], arr[j]);
        }
    }
}

template void exchange_sort<int>(int*, std::size_t);
template void exchange_sort<double>(double*, std::size_t);