#include "bob.h"
#include <algorithm>
#include <cctype>
#include <pstl/glue_algorithm_defs.h>

namespace bob {
const std::string hey(std::string const &str) {
  auto strx = str;
  strx.erase(std::remove_if(strx.begin(), strx.end(),
                            [](const char c) { return std::isspace(c); }),
             strx.end());

  if (strx.empty())
    return "Fine. Be that way!";

  bool question = strx.back() == '?';
  bool alpha_exist{};
  bool lower_exist{};

  for (auto c : strx) {
    if (std::isalpha(c))
      alpha_exist = true;
    if (std::islower(c))
      lower_exist = true;
  }

  if (question && !lower_exist && alpha_exist) {
    return "Calm down, I know what I'm doing!";
  }

  if (question)
    return "Sure.";

  if (!lower_exist && alpha_exist)
    return "Whoa, chill out!";

  return "Whatever.";
}

} // namespace bob
