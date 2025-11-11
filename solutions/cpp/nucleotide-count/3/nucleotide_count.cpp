#include "nucleotide_count.h"

#include <cctype>
#include <cstddef>
#include <cstring>
#include <stdexcept>
#include <string>

namespace nucleotide_count {
std::map<char, int> count(const char *c) {
  std::map<char, int> tmp{{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
  for (size_t i = 0; i < std::strlen(c); i++) {
    if (tmp.find(c[i]) == tmp.end()) {
      throw std::invalid_argument("error");
    } else {
      tmp[c[i]]++;
    }
  }
  return tmp;
}
}  // namespace nucleotide_count
