#include "leap.h"

namespace leap {
bool is_leap_year(int test) {
  if (test % 100 == 0 && (test % 400 != 0))
    return false;
  if (test % 4 == 0)
    return true;

  return false;
}
} // namespace leap
