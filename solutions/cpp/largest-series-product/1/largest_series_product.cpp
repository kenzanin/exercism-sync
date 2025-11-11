#include "largest_series_product.h"
#include <cctype>
#include <cstddef>
#include <numeric>
#include <stdexcept>

namespace largest_series_product {

std::size_t largest_product(std::string const &str, std::size_t len) {

  if (str.length() < len) {
    throw std::domain_error("");
  }

  std::size_t result{};
  for (std::size_t i = 0; i <= str.length() - len; i++) {
    auto tmp01 = str.substr(i, len);

    std::size_t sum = std::accumulate(tmp01.begin(), tmp01.end(), 1,
                                      [](std::size_t a, char b) -> std::size_t {
                                        if (!std::isdigit(b)) {
                                          throw std::domain_error("");
                                        }
                                        a *= (b - '0');
                                        return a;
                                      });
    result = result > sum ? result : sum;
  }

  return result;
}
} // namespace largest_series_product