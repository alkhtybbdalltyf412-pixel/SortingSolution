#include "binary_insertion_sort.h"

template <typename T>
void binary_insertion_sort(T* arr, std::size_t n) {
    for (std::size_t i = 1; i < n; ++i) {
        T key = arr[i];
        std::size_t left = 0;
        std::size_t right = i;

        while (left < right) {
            std::size_t mid = left + (right - left) / 2;
            if (arr[mid] > key)
                right = mid;
            else
                left = mid + 1;
        }

        for (std::size_t j = i; j > left; --j) {
            arr[j] = arr[j - 1];
        }
        arr[left] = key;
    }
}

template void binary_insertion_sort<int>(int*, std::size_t);
template void binary_insertion_sort<double>(double*, std::size_t);