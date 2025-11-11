#if !defined(CLOCK_H)
#define CLOCK_H
#include <string>

namespace date_independent {
class clock {
  int minutes{};

public:
  explicit clock(int);
  static clock at(const int hour, const int minute);
  clock plus(const int minute);
  operator std::string() const;
  bool operator==(const clock clk) const;
  bool operator!=(const clock clk) const;
};
} // namespace date_independent

#endif // CLOCK_H