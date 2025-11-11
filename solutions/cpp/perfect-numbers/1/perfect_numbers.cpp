#include "perfect_numbers.h"

#include <cmath>
#include <vector>

namespace perfect_numbers {
enum_classify classify(int in1) {
  int tmp{};
  for (int i = 1; i <= in1 / 2; i++) {
    double x = (in1 / i) * 1.0;
    if (std::floor(x) == std::ceil(x)) {
      tmp += i;
    }
  }
  return tmp == in1 ? perfect : tmp < in1 ? deficient : abundant;
}
}  // namespace perfect_numbers
