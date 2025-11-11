#include "word_count.h"

namespace word_count {
std::map<std::string, int> words(const std::string &str) {

  /*
     std::replace_if(
         tmp.begin(), tmp.end(), [](const char &c) { return !std::isalnum(c); },
         ' ');
   */

  std::string tmp{};
  std::for_each(str.begin(), str.end(), [&tmp](const char &c) {
    if (std::isalnum(c) || c == '\'') {
      tmp.push_back(std::tolower(c));
    } else {
      tmp.push_back(' ');
    }
  });

  auto replace_with_space = [](std::string &str, const std::string &find) {
    size_t i{};
    while ((i = str.find(find, i)) != str.npos) {
      // str = str.erase(i, 1);
      str = str.replace(i, 2, " ");
    }
  };

  tmp = " " + tmp + " "; // for case like " 'this'" -> " 'this' " -> "'this'"
  replace_with_space(tmp, "  ");
  replace_with_space(tmp, " '");
  replace_with_space(tmp, "' ");

  std::map<std::string, int> map{};
  std::stringstream ss(tmp);
  tmp.clear();
  while (std::getline(ss, tmp, ' ')) {
    if (tmp == "")
      continue;
    map[tmp]++;
  }
  return map;
}
} // namespace word_count
