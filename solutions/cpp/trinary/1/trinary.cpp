#include "trinary.h"
#include "string"
#include <cctype>
#include <cmath>
namespace trinary {
int to_decimal(std::string test) {
  if (test == "0")
    return 0;

  int var01 = test.size() - 1;
  int result{};

  for (auto c : test) {
    if (std::isalpha(c))
      return 0;
    int d = c - '0';
    int tmp = std::pow(3, var01);
    result += d * tmp;
    var01--;
  }

  return result;
}
} // namespace trinary
