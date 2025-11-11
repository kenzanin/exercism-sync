#include <vector>
#if !defined(ANAGRAM_H)
#define ANAGRAM_H
#include <algorithm>
#include <cctype>
#include <deque>
#include <string>
#include <vector>

namespace anagram {
class anagram {
  std::string word{};
  std::string tolow(const std::string &str) {
    std::string result(str);
    std::transform(result.begin(), result.end(), result.begin(),
                   [](const char &c) { return std::tolower(c); });
    return result;
  }

public:
  explicit anagram(const std::string &);
  const std::vector<std::string> matches(const std::vector<std::string> &);
};

} // namespace anagram

#endif // ANAGRAM_H