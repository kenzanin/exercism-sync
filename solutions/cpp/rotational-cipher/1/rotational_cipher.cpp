#include "rotational_cipher.h"
#include <array>
#include <cctype>
#include <vector>

namespace rotational_cipher {
std::string rotate(const std::string &in1, int in2) {
  std::vector<int> data(in1.begin(), in1.end());
  in2 = in2 >= 26 ? 0 : in2;
  std::array<char, 2> x{};
  for (auto &e : data) {
    if (std::isalpha(e)) {
      x = {'Z', 'A'};
      if (std::islower(e)) {
        x = {'z', 'a'};
      }
      e += in2;
      if (e > x[0]) {
        e = x[1] + (e - x[0]) - 1;
      }
    }
  }
  return std::string(data.begin(), data.end());
}
} // namespace rotational_cipher
