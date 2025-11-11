#include "secret_handshake.h"
#include "algorithm"
#include <string>
#include <vector>

namespace secret_handshake {
std::vector<std::string> commands(int test) {
  std::string wink = "wink", double_blink = "double blink",
              close_eyes = "close your eyes", jump = "jump";

  std::vector<std::string> result{};
  if (test & 0x01) {
    result.push_back(wink);
  }
  if (test & 0x02) {
    result.push_back(double_blink);
  }
  if (test & 0x04) {
    result.push_back(close_eyes);
  }
  if (test & 0x08) {
    result.push_back(jump);
  }
  if (test & 0x10) {
    std::reverse(result.begin(), result.end());
  }

  return result;
}
} // namespace secret_handshake
