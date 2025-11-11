#include "acronym.h"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

namespace acronym {
const std::string acronym(const std::string &input) {
  std::string result{input};
  std::replace_copy_if(
      input.begin(), input.end(), result.begin(),
      [&](char c) { return (c == '_' || c == '-'); }, ' ');
  std::istringstream ss(result);

  std::string var{};
  result.clear();
  while (ss >> var) {
    result.push_back(toupper(var.at(0)));
  }
  return result;
}
} // namespace acronym
