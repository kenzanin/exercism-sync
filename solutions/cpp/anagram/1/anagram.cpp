#include "anagram.h"

namespace anagram {
anagram::anagram(const std::string &str) : word(str) {}

const std::vector<std::string>
anagram::matches(const std::vector<std::string> &list) {
  word = tolow(word);
  std::string tmp01(word);
  std::sort(tmp01.begin(), tmp01.end());

  std::vector<std::string> result{};
  for (std::string str : list) {
    std::string tmp02 = tolow(str);
    if (word == tmp02)
      continue;
    std::sort(tmp02.begin(), tmp02.end());
    if (tmp02 == tmp01) {
      result.push_back(str);
    }
  }
  return result;
}
} // namespace anagram
