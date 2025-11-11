#include "prime_factors.h"
#include <cmath>
#include <regex>
#include <vector>

namespace prime_factors {
std::vector<int> of(int n) {

  if (n == 2 || n == 3) {
    return {n};
  }

  auto clean = [](double a) -> bool {
    double b = std::floor(a);
    return a == b;
  };

  std::vector<int> result{};
  int tmp02 = n;
  for (int i = 2; i < n; i++) {
    double tmp01 = tmp02 / (double)i;
    if (clean(tmp01)) {
      tmp02 = tmp01;
      result.push_back(i);
      i = 1;
    }
  }

  return result;
}
} // namespace prime_factors
