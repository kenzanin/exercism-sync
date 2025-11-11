#include "secret_handshake.h"

#include <list>

namespace secret_handshake {
std::vector<std::string> commands(int test) {
  auto const respond = std::array<const char*, 4>{"wink", "double blink",
                                                  "close your eyes", "jump"};
  auto tmp = std::list<std::string>{};
  for (auto i = 0; i < 4; i++) {
    if (test & (1 << i)) {
      if (test & 0x10)
        tmp.push_front(respond[i]);
      else
        tmp.push_back(respond[i]);
    }
  }
  return std::vector<std::string>{tmp.begin(), tmp.end()};
}
}  // namespace secret_handshake
