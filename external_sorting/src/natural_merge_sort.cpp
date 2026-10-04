#include "natural_merge_sort.h"
#include <cstddef>
#include <cstdio>
#include <fstream>

namespace {

    template <typename T>
    bool read_item(std::ifstream& in, T& x) {
        return static_cast<bool>(in.read(reinterpret_cast<char*>(&x), sizeof(T)));
    }

    template <typename T>
    void write_item(std::ofstream& out, const T& x) {
        out.write(reinterpret_cast<const char*>(&x), sizeof(T));
    }

    // توزيع حسب السلاسل الطبيعية: نبدّل الملف كلما صار نزول. يرجع عدد السلاسل
    template <typename T>
    std::size_t distribute(const std::string& a_name, const std::string& b_name,
        const std::string& c_name) {
        std::ifstream a(a_name, std::ios::binary);
        std::ofstream b(b_name, std::ios::binary | std::ios::trunc);
        std::ofstream c(c_name, std::ios::binary | std::ios::trunc);
        std::size_t runs = 0;
        bool to_b = true;
        T x{}, prev{};
        while (read_item(a, x)) {
            if (runs == 0) {
                runs = 1;
            }
            else if (x < prev) {
                to_b = !to_b;
                ++runs;
            }
            write_item(to_b ? b : c, x);
            prev = x;
        }
        return runs;
    }

    // دمج السلاسل الطبيعية من B و C إلى A
    template <typename T>
    void merge_back(const std::string& a_name, const std::string& b_name,
        const std::string& c_name) {
        std::ifstream b(b_name, std::ios::binary);
        std::ifstream c(c_name, std::ios::binary);
        std::ofstream a(a_name, std::ios::binary | std::ios::trunc);
        T xb{}, xc{};
        bool hb = read_item(b, xb);
        bool hc = read_item(c, xc);
        while (hb || hc) {
            bool b_run = hb;
            bool c_run = hc;
            while (b_run || c_run) {
                bool take_b = (b_run && c_run) ? !(xc < xb) : b_run;
                if (take_b) {
                    write_item(a, xb);
                    T prev = xb;
                    hb = read_item(b, xb);
                    if (!hb || xb < prev) b_run = false;
                }
                else {
                    write_item(a, xc);
                    T prev = xc;
                    hc = read_item(c, xc);
                    if (!hc || xc < prev) c_run = false;
                }
            }
        }
    }

}  // namespace

template <typename T>
void natural_merge_sort(const std::string& filename) {
    const std::string b_name = filename + ".tmp_b";
    const std::string c_name = filename + ".tmp_c";

    while (true) {
        std::size_t runs = distribute<T>(filename, b_name, c_name);
        if (runs <= 1) break;  // الملف مرتب (أو فاضي)
        merge_back<T>(filename, b_name, c_name);
    }

    std::remove(b_name.c_str());
    std::remove(c_name.c_str());
}

template void natural_merge_sort<int>(const std::string&);
template void natural_merge_sort<double>(const std::string&);