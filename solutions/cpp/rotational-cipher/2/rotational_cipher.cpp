#include "rotational_cipher.h"
#include <cctype>
#include <string>
#include <vector>

namespace rotational_cipher {
std::string rotate(const std::string &in1, int in2) {
  std::string data(in1);
  in2 = in2 >= 26 ? 0 : in2;
  for (auto &e : data) {
    if (std::isalpha(e)) {
      char x = std::islower(e) ? 'z' : 'Z';
      int ee = e + in2;
      if (ee > x) {
        ee = (x - 26) + (ee - x);
      }
      e = ee;
    }
  }
  return std::string(data.begin(), data.end());
}
} // namespace rotational_cipher
