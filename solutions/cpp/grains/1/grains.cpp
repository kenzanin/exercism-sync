#include "grains.h"
#include <cstdint>
#include <math.h>

namespace grains {
long square(int test) { return pow(2, test - 1); }

unsigned long total() {
  unsigned long tmp = 0;
  for (std::uint8_t i = 1; i <= 64; i++) {
    tmp += square(i);
  }
  return tmp;
}

} // namespace grains
