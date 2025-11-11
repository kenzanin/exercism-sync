#include "secret_handshake.h"

namespace secret_handshake {
std::vector<std::string> commands(int test) {
  auto const respond = std::array<const char*, 4>{"wink", "double blink",
                                                  "close your eyes", "jump"};
  std::vector<std::string> result{};
  for (auto i = 0; i < 4; i++) {
    if (test & (1 << i)) {
      result.push_back(respond[i]);
    }
  }
  return test & 0x10 ? std::vector<std::string>{result.rbegin(), result.rend()}
                     : result;
}
}  // namespace secret_handshake
