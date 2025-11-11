#include "perfect_numbers.h"

#include <inttypes.h>

#include <cmath>
#include <stdexcept>

namespace perfect_numbers {
enum_classify classify(int32_t in1) {
  if (in1 <= 0) throw std::domain_error("error");

  int32_t tmp{};
  for (int32_t i = 1; i <= in1 / 2; i++) {
    double x = in1 / (i * 1.0);
    if (std::floor(x) == x) {
      tmp += i;
    }
  }
  return tmp == in1 ? perfect : tmp < in1 ? deficient : abundant;
}
}  // namespace perfect_numbers
