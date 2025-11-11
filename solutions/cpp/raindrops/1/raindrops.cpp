#include "raindrops.h"
#include <string>

namespace raindrops {
std::string convert(int test) {
  std::string tmp{};
  if ((test % 3) == 0)
    tmp.append("Pling");
  if ((test % 5) == 0)
    tmp.append("Plang");
  if ((test % 7) == 0)
    tmp.append("Plong");
  if(tmp.empty())tmp=std::to_string(test);
  return tmp;
}
} // namespace raindrops
