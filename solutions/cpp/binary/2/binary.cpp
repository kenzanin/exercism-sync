#include "binary.h"
#include <cctype>
#include <cstdint>

namespace binary {
std::uint32_t convert(std::string test) {
  std::uint32_t result{};
  for (auto c : test) {
    if (std::isdigit(c)) {
      result <<= 1;
      if (c == '1') {
        result |= 1;
      }
    } else
      return 0;
  }
  return result;
}
} // namespace binary
