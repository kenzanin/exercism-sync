#include "all_your_base.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <vector>

namespace all_your_base {
std::vector<unsigned int> convert(const unsigned int base_in,
                                  const std::vector<unsigned int> &input,
                                  const unsigned int base_out) {
  if (base_in <= 1 || base_out <= 1)
    throw std::invalid_argument("");

  std::vector<unsigned int> result{};
  unsigned int to10{};
  for (int i = input.size() - 1; i >= 0; i--) {
    if (input.at(i) >= base_in)
      throw std::invalid_argument("");
    unsigned int tmp = input.at(i);
    to10 += tmp * std::pow(base_in, (input.size() - 1) - i);
  }

  for (int i = to10; i > 0; i /= base_out) {
    result.push_back(i % base_out);
  }

  std::reverse(result.begin(), result.end());
  return result;
}
} // namespace all_your_base
