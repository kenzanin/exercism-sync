#include "series.h"
#include <cstddef>
#include <exception>
#include <stdexcept>
#include <vector>

namespace series {
std::vector<std::string> slice(std::string const &str, int slice) {

  if (str.length() < static_cast<size_t>(slice) || slice <= 0) {
    throw std::domain_error("domain_error");
  }

  std::vector<std::string> result{};

  for (size_t i = 0; i <= str.length() - slice; i++) {
    result.push_back(str.substr(i, slice));
  }

  return result;
}
} // namespace series
