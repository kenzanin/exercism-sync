#include "roman_numerals.h"
#include <algorithm>
#include <string>
#include <unordered_map>

namespace roman_numerals {
static std::unordered_map<int, std::string> map{
    {1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
    {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
    {500, "D"}, {900, "CM"}, {1000, "M"}};

const std::string helper(const int input, const int base) {
  std::string tmp{};
  int i = input % base;
  i = (i / (base / 10)) * (base / 10);
  for (; i > 0;) {
    if (!map[i].empty()) {
      tmp = map[i] + tmp;
      i = 0;
    } else {
      tmp = map[(base / 10)] + tmp;
      i -= (base / 10);
    }
  }
  return tmp;
}

const std::string convert(const int input) {
  std::string result{};
  result += helper(input, 1000);
  result += helper(input, 100);
  result += helper(input, 10);
  return result;
}

} // namespace roman_numerals
