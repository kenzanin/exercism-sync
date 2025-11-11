#include "etl.h"
#include <cctype>

namespace etl {
std::map<char, int> transform(const std::map<int, std::vector<char>>);
} // namespace etl

std::map<char, int> etl::transform(const std::map<int, std::vector<char>> old) {
  std::map<char, int> result{};
  for (std::pair<int, std::vector<char>> i : old) {
    for (auto var : i.second)
      result.insert(std::pair<char, int>(std::tolower(var), i.first));
  }

  return result;
}
