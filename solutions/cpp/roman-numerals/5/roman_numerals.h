#if !defined(ROMAN_NUMERALS_H)
#define ROMAN_NUMERALS_H
#include <string>
#include <unordered_map>

namespace roman_numerals {
enum class e_satuan { SATUAN = 1, PULUHAN = 10, RATUSAN = 100, RIBUAN = 1000 };
const std::string convert(const int);
const std::string helper(const int input, e_satuan satuan);
} // namespace roman_numerals

#endif // ROMAN_NUMERALS_H