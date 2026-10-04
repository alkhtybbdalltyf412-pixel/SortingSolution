#include "one_phase_merge_sort.h"
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <utility>

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

    // توزيع أولي واحد: سلاسل طولها 1 بالتناوب على ملفين
    template <typename T>
    void initial_distribute(const std::string& src, const std::string& f1,
        const std::string& f2) {
        std::ifstream a(src, std::ios::binary);
        std::ofstream o1(f1, std::ios::binary | std::ios::trunc);
        std::ofstream o2(f2, std::ios::binary | std::ios::trunc);
        bool first = true;
        T x;
        while (read_item(a, x)) {
            write_item(first ? o1 : o2, x);
            first = !first;
        }
    }

    // دمج من ملفين مدخلين إلى ملفين مخرجين بالتناوب
    template <typename T>
    void merge_pass(const std::string& in1, const std::string& in2,
        const std::string& out1, const std::string& out2,
        std::size_t run) {
        std::ifstream b(in1, std::ios::binary);
        std::ifstream c(in2, std::ios::binary);
        std::ofstream o1(out1, std::ios::binary | std::ios::trunc);
        std::ofstream o2(out2, std::ios::binary | std::ios::trunc);
        T xb{}, xc{};
        bool hb = read_item(b, xb);
        bool hc = read_item(c, xc);
        bool to_first = true;
        while (hb || hc) {
            std::ofstream& out = to_first ? o1 : o2;
            std::size_t nb = 0, nc = 0;
            while ((hb && nb < run) || (hc && nc < run)) {
                bool b_ok = hb && nb < run;
                bool c_ok = hc && nc < run;
                if (b_ok && (!c_ok || !(xc < xb))) {
                    write_item(out, xb);
                    ++nb;
                    hb = read_item(b, xb);
                }
                else {
                    write_item(out, xc);
                    ++nc;
                    hc = read_item(c, xc);
                }
            }
            to_first = !to_first;
        }
    }

    template <typename T>
    void copy_file(const std::string& from, const std::string& to) {
        std::ifstream in(from, std::ios::binary);
        std::ofstream out(to, std::ios::binary | std::ios::trunc);
        T x;
        while (read_item(in, x)) write_item(out, x);
    }

}  // namespace

template <typename T>
void one_phase_merge_sort(const std::string& filename) {
    const std::size_t n = count_items<T>(filename);
    if (n < 2) return;

    std::string in1 = filename + ".tmp1";
    std::string in2 = filename + ".tmp2";
    std::string out1 = filename + ".tmp3";
    std::string out2 = filename + ".tmp4";

    initial_distribute<T>(filename, in1, in2);

    for (std::size_t run = 1; run < n; run *= 2) {
        merge_pass<T>(in1, in2, out1, out2, run);
        std::swap(in1, out1);
        std::swap(in2, out2);
    }

    // بعد آخر مرور صارت السلسلة الوحيدة المرتبة بـ in1
    copy_file<T>(in1, filename);

    std::remove(in1.c_str());
    std::remove(in2.c_str());
    std::remove(out1.c_str());
    std::remove(out2.c_str());
}

template void one_phase_merge_sort<int>(const std::string&);
template void one_phase_merge_sort<double>(const std::string&);