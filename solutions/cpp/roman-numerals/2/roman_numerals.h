#if !defined(ROMAN_NUMERALS_H)
#define ROMAN_NUMERALS_H
#include <string>

namespace roman_numerals {
const std::string convert(const int);
const std::string helper(const int input, const int base);
} // namespace roman_numerals

#endif // ROMAN_NUMERALS_H