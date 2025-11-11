#include "parallel_letter_frequency.h"

namespace parallel_letter_frequency {
std::unordered_map<char, int> frequency(
    std::vector<std::string_view> const &in) {
  auto ret = std::unordered_map<char, int>{};
  for (auto const &e : in) {
    for (auto const &ee : std::string(e)) {
      if (!std::isalpha(ee)) continue;
      ret[std::tolower(ee)]++;
    }
  }
  return ret;
}
}  // namespace parallel_letter_frequency
