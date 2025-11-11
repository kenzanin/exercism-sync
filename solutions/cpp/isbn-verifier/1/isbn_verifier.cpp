#include "isbn_verifier.h"
#include <cctype>
#include <cstddef>

namespace isbn_verifier {
bool is_valid(std::string const &str) {
  if (str.empty()) {
    return false;
  }
  int count = 1;
  int sum{};
  for (int i = str.length() - 1; i >= 0; i--) {
    if (count > 10)
      return false;

    if (isdigit(str.at(i))) {
      sum += (str.at(i) - '0') * count;
      count++;
      continue;
    } else if (i == (int)(str.length() - 1) && str.at(i) == 'X') {
      sum += 10;
      count++;
      continue;
    } else if (isalpha(str.at(i)))
      return false;
  }
  return (sum % 11) == 0 && sum > 10;
}
} // namespace isbn_verifier