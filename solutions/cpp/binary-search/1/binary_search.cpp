#include "binary_search.h"
#include <cstddef>
#include <stdexcept>
#include <vector>

namespace binary_search {

int binary_search(std::vector<int> const &data, int value, std::size_t start,
                  std::size_t end) {

  while (end >= start) {
    auto mid = start + (end - start) / 2;
    if (data[mid] == value) {
      return mid;
    }
    if (data[mid] > value) {
      return binary_search(data, value, start, mid - 1);
    }
    return binary_search(data, value, mid + 1, end);
  }
  throw std::domain_error("");
  // return 0;
}

int find(std::vector<int> const &data, int n) {
  if (data.empty()) {
    throw std::domain_error("");
  }
  if (data[0] > n) {
    throw std::domain_error("");
  }
  return binary_search(data, n, 0, data.size());
}

} // namespace binary_search
