#include "eliuds_eggs.h"
#include <cstdint>

namespace chicken_coop {
uint64_t positions_to_quantity(uint64_t in1) {
  int eggs = 0;
  while (in1 > 0) {
    if ((in1 & 1) == 1)
      eggs++;
    in1 >>= 1;
  }
  return eggs;
}
} // namespace chicken_coop
