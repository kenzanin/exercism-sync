#include "resistor_color_duo.h"
#include <algorithm>
#include <iterator>
#include <vector>

namespace resistor_color_duo {
int value(const std::vector<std::string> in1) {
  int value =
      std::distance(cc.begin(), std::find(cc.begin(), cc.end(), in1[0]));
  value *= 10;
  value += (std::distance(cc.begin(), std::find(cc.begin(), cc.end(), in1[1])));
  return value;
}
} // namespace resistor_color_duo
