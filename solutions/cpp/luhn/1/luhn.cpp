#include "luhn.h"
#include <bits/stdint-uintn.h>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>

namespace luhn {
bool valid(std::string test) {
  std::vector<int8_t> var{};
  for (auto c : test) {
    if (std::isspace(c))
      continue;
    if (std::isdigit(c)) {
      var.push_back(c - '0');
      continue;
    }
    return false;
  }

  if (var.size() < 2)
    return false;

  int var01{};
  int ii{};
  for (int i = int(var.size() - 1); i >= 0; i--) {
    if (ii & 0x1) {
      var[i] *= 2;
      var[i] > 9 ? var[i] -= 9 : 0;
    }
    var01 += var[i];
    ii++;
  }

  return (var01 % 10) == 0;
}

} // namespace luhn
