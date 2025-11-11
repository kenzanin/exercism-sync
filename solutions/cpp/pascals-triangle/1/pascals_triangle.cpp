#include "pascals_triangle.h"
#include <vector>

namespace pascals_triangle {
const std::vector<std::vector<int>> generate_rows(int test) {
  std::vector<std::vector<int>> var{};
  var.resize(test);
  if (test == 0)
    return var;
  for (int i = 0; i < test; i++) {
    for (int ii = 0; ii <= i; ii++) {
      if (ii == 0) {
        var[i].push_back(1);
        continue;
      }
      if (ii == i) {
        var[i].push_back(1);
        continue;
      }
      var[i].push_back(var[i - 1][ii - 1] + var[i - 1][ii]);
    }
  }
  return var;
}
} // namespace pascals_triangle
