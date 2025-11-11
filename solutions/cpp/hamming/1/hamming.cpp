#include "hamming.h"
#include "cstdlib"
#include "stdlib.h"
#include <cstdlib>
#include <stdexcept>
#include <string>

namespace hamming {
int compute(std::string, std::string);
} // namespace hamming

int hamming::compute(std::string a, std::string b) {
  int result = 0;
  if (a.size() != b.size())
    throw std::domain_error("whatever");
  for (int i = 0; i < (int)a.size(); i++) {
    if (a[i] != b[i]) {
      result++;
    }
  }
  return result;
}
