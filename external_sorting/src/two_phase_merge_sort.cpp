#include "two_phase_merge_sort.h"
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

    template <typename T>
    std::size_t count_items(const std::string& name) {
        std::ifstream in(name, std::ios::binary | std::ios::ate);
        if (!in) return 0;
        return static_cast<std::size_t>(in.tellg()) / sizeof(T);
    }

    // المرحلة 1: توزيع سلاسل طولها run بالتناوب على B و C
    template <typename T>
    void distribute(const std::string& a_name, const std::string& b_name,
        const std::string& c_name, std::size_t run) {
        std::ifstream a(a_name, std::ios::binary);
        std::ofstream b(b_name, std::ios::binary | std::ios::trunc);
        std::ofstream c(c_name, std::ios::binary | std::ios::trunc);
        bool to_b = true;
        std::size_t cnt = 0;
        T x;
        while (read_item(a, x)) {
            write_item(to_b ? b : c, x);
            if (++cnt == run) {
                cnt = 0;
                to_b = !to_b;
            }
        }
    }

    // المرحلة 2: دمج سلاسل B و C (طول كل واحدة run) وكتابتها بـ A
    template <typename T>
    void merge_back(const std::string& a_name, const std::string& b_name,
        const std::string& c_name, std::size_t run) {
        std::ifstream b(b_name, std::ios::binary);
        std::ifstream c(c_name, std::ios::binary);
        std::ofstream a(a_name, std::ios::binary | std::ios::trunc);
        T xb{}, xc{};
        bool hb = read_item(b, xb);
        bool hc = read_item(c, xc);
        while (hb || hc) {
            std::size_t nb = 0, nc = 0;
            while ((hb && nb < run) || (hc && nc < run)) {
                bool b_ok = hb && nb < run;
                bool c_ok = hc && nc < run;
                if (b_ok && (!c_ok || !(xc < xb))) {
                    write_item(a, xb);
                    ++nb;
                    hb = read_item(b, xb);
                }
                else {
                    write_item(a, xc);
                    ++nc;
                    hc = read_item(c, xc);
                }
            }
        }
    }

}  // namespace

template <typename T>
void two_phase_merge_sort(const std::string& filename) {
    const std::size_t n = count_items<T>(filename);
    if (n < 2) return;

    const std::string b_name = filename + ".tmp_b";
    const std::string c_name = filename + ".tmp_c";

    for (std::size_t run = 1; run < n; run *= 2) {
        distribute<T>(filename, b_name, c_name, run);
        merge_back<T>(filename, b_name, c_name, run);
    }

    std::remove(b_name.c_str());
    std::remove(c_name.c_str());
}

template void two_phase_merge_sort<int>(const std::string&);
template void two_phase_merge_sort<double>(const std::string&);