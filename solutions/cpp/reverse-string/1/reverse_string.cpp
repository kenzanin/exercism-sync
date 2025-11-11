#include "reverse_string.h"
#include <algorithm>
#include <iterator>
#include <string>

namespace reverse_string {
std::string reverse_string(std::string test);
} // namespace reverse_string

std::string reverse_string::reverse_string(std::string test) {
  std::reverse_iterator<std::string::iterator> r = test.rbegin();
  std::string rev(r, test.rend());
  return rev;
}