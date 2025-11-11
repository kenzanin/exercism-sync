#include "atbash_cipher.h"
#include <cctype>
#include <string>

/*
Plain:  abcdefghijklmnopqrstuvwxyz
Cipher: zyxwvutsrqponmlkjihgfedcba
*/

namespace atbash_cipher {
std::string encode(std::string test) {
  std::string dict{"zyxwvutsrqponmlkjihgfedcba"};
  std::string result{};
  int sp{};
  for (auto c : test) {
    c = std::tolower(c);
    if (!std::isalnum(c))
      continue;
    if (sp == 5) {
      sp = 0;
      result.push_back(' ');
    }
    if (std::isalpha(c)) {
      result.push_back('z'+'a'-c);      
    } else if (std::isdigit(c)) {
      result.push_back(c);
    }
    sp++;
  }
  return result;
}

std::string decode(std::string test) {
  std::string result{};

  for (auto c : test) {
    if (!std::isalnum(c))
      continue;
    if (std::isspace(c))
      continue;

    if (std::isdigit(c)) {
      result.push_back(c);
    } else if (std::isalpha(c))
      result.push_back(('z' - c) + 'a');
  }
  return result;
}
} // namespace atbash_cipher
