#include "acronym.h"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
 
namespace acronym {
std::string acronym(std::string test) { 
  std::vector<std::string> tmp{};
  std::string var{};
  std::string tmp2{};

  std::replace(test.begin(), test.end(), '-', ' ');
  std::istringstream ss(test);

  while (ss >> var) {
    tmp.push_back(var);
  }

  for (int i = 0; i < (int)tmp.size(); i++)
    tmp2 += std::toupper(tmp[i].at(0));

  return tmp2;
}
} // namespace acronym
