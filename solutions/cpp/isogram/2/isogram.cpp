#include "isogram.h"
#include <algorithm>
#include <cctype>
#include <unordered_map>

namespace isogram {

bool is_isogram(std::string const &test) {

  std::unordered_map<char, bool> map{};

  bool result = true;
  std::for_each(test.begin(), test.end(), [&result, &map](char a) {
    if (a == ' ' || a == '-')
      ;
    else {
      a = std::tolower(a);
      if (map[a] == true) {
        result = false;
        return;
      }
      map[a] = true;
    }
  });

  return result;
}
} // namespace isogram
