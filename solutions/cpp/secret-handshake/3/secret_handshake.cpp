#include "secret_handshake.h"

namespace secret_handshake {
std::vector<std::string> commands(int test) {
  std::array<std::string, 4> const respond = {"wink", "double blink",
                                              "close your eyes", "jump"};
  std::vector<std::string> result{};
  for (auto i = 0; i < 4; i++) {
    if (test & (1 << i)) {
      result.push_back(respond[i]);
    }
  }
  if (test & 0x10) {
    std::reverse(result.begin(), result.end());
  }

  return result;
}
}  // namespace secret_handshake
