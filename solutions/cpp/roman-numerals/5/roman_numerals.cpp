#include "roman_numerals.h"
#include <algorithm>
#include <string>
#include <type_traits>
#include <unordered_map>

namespace roman_numerals {
static const std::unordered_map<int, std::string> map{
    {1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
    {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
    {500, "D"}, {900, "CM"}, {1000, "M"}};

const std::string helper(const int input, e_satuan satuan) {
  std::string tmp{};
  const int s = static_cast<std::underlying_type<e_satuan>::type>(satuan);

  int i = input % (s * 10);
  i = (i / s) * s;
  for (; i > 0;) {
    if (map.find(i) != map.end()) {
      tmp = map.at(i) + tmp;
      i = 0;
    } else {
      tmp = map.at(s) + tmp;
      i -= s;
    }
  }
  return tmp;
}

const std::string convert(const int input) {
  std::string result{};
  result += helper(input, e_satuan::RIBUAN);
  result += helper(input, e_satuan::RATUSAN);
  result += helper(input, e_satuan::PULUHAN);
  result += helper(input, e_satuan::SATUAN);
  return result;
}

} // namespace roman_numerals
