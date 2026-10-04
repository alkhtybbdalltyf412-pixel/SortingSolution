#include "quick_sort.h"
#include <cstddef>
#include <utility>

namespace {

    template <typename T>
    void quick_sort_impl(T* arr, std::ptrdiff_t low, std::ptrdiff_t high) {
        while (low < high) {
            T pivot = arr[low + (high - low) / 2];
            std::ptrdiff_t i = low;
            std::ptrdiff_t j = high;

            while (i <= j) {
                while (arr[i] < pivot) ++i;
                while (arr[j] > pivot) --j;
                if (i <= j) {
                    std::swap(arr[i], arr[j]);
                    ++i;
                    --j;
                }
            }

            if (j - low < high - i) {
                quick_sort_impl(arr, low, j);
                low = i;
            }
            else {
                quick_sort_impl(arr, i, high);
                high = j;
            }
        }
    }

}  // namespace

template <typename T>
void quick_sort(T* arr, std::size_t n) {
    if (n < 2) return;
    quick_sort_impl(arr, 0, static_cast<std::ptrdiff_t>(n) - 1);
}

template void quick_sort<int>(int*, std::size_t);
template void quick_sort<double>(double*, std::size_t);