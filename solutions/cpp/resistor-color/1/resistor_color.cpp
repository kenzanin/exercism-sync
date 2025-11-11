#include "resistor_color.h"
#include <algorithm>
#include <iterator>

namespace resistor_color {
int color_code(std::string const &in1) {
  return std::distance(cc.begin(), std::find(cc.begin(), cc.end(), in1));
}

std::vector<std::string> colors() {
  return cc;
}
} // namespace resistor_color
