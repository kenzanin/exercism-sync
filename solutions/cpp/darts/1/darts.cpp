#include "darts.h"
#include <cmath>

namespace darts {

double score(double x, double y) {
  double tmp = std::abs(x) + std::abs(y);
  tmp /= 2.0;
  if (tmp > 7.0) {
    return 0.0;
  } else if (tmp > 3.5 && tmp <= 7.0) {
    return 1.0;
  } else if (tmp <= 3.5 && tmp > 0.7) {
    return 5.0;
  } else if (tmp <= 0.7) {
    return 10;
  }
  return 0.0;
}

} // namespace darts