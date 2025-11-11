#include "isogram.h"
#include "iostream"
#include "string"
#include <cctype>
#include <vector>

namespace isogram {

bool is_isogram(const std::string test) {
  for (int i = 0; i < (int)test.size(); i++) {
    if (test[i] == ' ' || test[i]=='-')
      continue;
    for (int ii = i + 1; ii < (int)test.size(); ii++) {
      if (std::tolower(test[i]) == std::tolower(test[ii]))
        return false;
    }
  }
  return true;
}
} // namespace isogram
