#include "grains.h"
#include "math.h"

uint64_t square(uint8_t index) {
  if (index >= 65)
    return 0;
  return pow(2, index - 1);
}

uint64_t total(void) {
  uint64_t result = 0;
  for (int i = 1; i <= 64; i++) {
    result += square(i);
  }
  return result;
}
