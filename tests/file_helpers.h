#pragma once
#include <fstream>
#include <string>
#include <vector>

template <typename T>
void write_binary(const std::string& name, const std::vector<T>& v) {
    std::ofstream out(name, std::ios::binary | std::ios::trunc);
    if (!v.empty())
        out.write(reinterpret_cast<const char*>(v.data()), v.size() * sizeof(T));
}

template <typename T>
std::vector<T> read_binary(const std::string& name) {
    std::ifstream in(name, std::ios::binary);
    std::vector<T> v;
    T x;
    while (in.read(reinterpret_cast<char*>(&x), sizeof(T))) v.push_back(x);
    return v;
}

inline bool file_exists(const std::string& name) {
    std::ifstream f(name, std::ios::binary);
    return f.good();
}
