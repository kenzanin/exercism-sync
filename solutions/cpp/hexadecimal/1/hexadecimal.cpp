#include "hexadecimal.h"
#include "test/catch.hpp"
#include <cstdint>

namespace hexadecimal {
std::uint32_t convert(std::string test) {
  std::uint32_t result{};
  for (auto c : test) {
    if (c >= '0' && c <= '9') {
      result <<= 4;
      result |= (c - '0');
    } else if (c >= 'a' && c <= 'f') {
      result <<= 4;
      result |= (c - 'a') + 10;
    } else {
      return 0;
    }
  }
  return result;
}
} // namespace hexadecimal
