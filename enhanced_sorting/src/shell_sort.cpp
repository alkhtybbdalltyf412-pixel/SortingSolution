#include "shell_sort.h"

template <typename T>
void shell_sort(T* arr, std::size_t n) {
    for (std::size_t gap = n / 2; gap > 0; gap /= 2) {
        for (std::size_t i = gap; i < n; ++i) {
            T temp = arr[i];
            std::size_t j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

template void shell_sort<int>(int*, std::size_t);
template void shell_sort<double>(double*, std::size_t);