#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {
int steps(int test) {
  if(test<=0)throw std::domain_error("error");

  int tmp{};
  int tmp2{};
  for (tmp = test; tmp > 1;) {
    if (tmp & 0x01) {
      tmp *= 3;
      tmp += 1;
    } else {
      tmp /= 2;
    }
    tmp2++;
  }
  return tmp2;
}
} // namespace collatz_conjecture
