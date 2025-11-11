#include "sieve.h"
#include <cstddef>

namespace sieve {

std::vector<int> primes(std::size_t to) {
  if (to < 2)
    return {};
  if (to == 2)
    return {2};

  std::unordered_map<int, bool> list{};
  std::vector<int> result{};

  for (size_t i = 2; i <= to; i++) {
    if (list[i] == false)
      result.push_back(i);

    std::size_t ii = i;
    for (int iii = 2; ii <= to; iii++) {
      list[ii] = true;
      ii = i * iii;
    }
  }

  return result;
}

} // namespace sieve
