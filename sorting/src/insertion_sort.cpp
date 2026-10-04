#include "insertion_sort.h"

template <typename T>
void insertion_sort(T* arr, std::size_t n) {
    for (std::size_t i = 1; i < n; ++i) {
        T key = arr[i];
        std::size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

template void insertion_sort<int>(int*, std::size_t);
template void insertion_sort<double>(double*, std::size_t);