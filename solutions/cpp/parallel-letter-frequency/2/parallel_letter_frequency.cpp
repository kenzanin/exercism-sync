#include "parallel_letter_frequency.h"

#include <execution>

namespace parallel_letter_frequency {

std::unordered_map<char, int> frequency(
    const std::vector<std::string_view>& _in_) {
  std::unordered_map<char, std::atomic<int>> ret;

  std::for_each(std::execution::par_unseq, _in_.begin(), _in_.end(),
                [&ret](const std::string_view& s) {
                  for (char c : s) {
                    if (std::isalpha(c)) {
                      ++ret[std::tolower(c)];
                    }
                  }
                });

  std::unordered_map<char, int> ret2{};
  for (auto const& e : ret) {
    ret2[e.first] = e.second;
  }
  return ret2;
}

}  // namespace parallel_letter_frequency