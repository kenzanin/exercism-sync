#include "clock.h"
#include <array>
#include <cstdio>
#include <string>

namespace date_independent {

clock::clock(int minute) { minutes = minute; }

clock clock::at(const int hour, const int minute) {
  int min = ((hour * 60) + minute) % (24 * 60);
  min = min < 0 ? (24 * 60) + min : min;
  return clock(min);
}

clock clock::plus(const int minute) {
  int min = (this->minutes + minute) % (24 * 60);
  min = min < 0 ? (24 * 60) + min : min;
  return clock(min);
}

clock::operator std::string() const {
  std::array<char, 10> str{};
  std::sprintf(str.begin(), "%02d:%02d", minutes / 60, minutes % 60);
  return str.data();
}

bool clock::operator==(const clock clk) const {
  return this->minutes == clk.minutes;
}
bool clock::operator!=(const clock clk) const {
  return this->minutes != clk.minutes;
}
} // namespace date_independent
