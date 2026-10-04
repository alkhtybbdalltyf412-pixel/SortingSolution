#pragma once
#include <string>

// يفرز ملف ثنائي (binary) من عناصر T مكانه باستخدام ملفات مؤقتة
template <typename T>
void two_phase_merge_sort(const std::string& filename);