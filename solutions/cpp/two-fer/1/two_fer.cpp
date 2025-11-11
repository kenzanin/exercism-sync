#include "two_fer.h"
#include <string>

namespace two_fer {
std::string two_fer() { return "One for you, one for me."; }

std::string two_fer(std::string test) {
  std::string tmp{};
  tmp = "One for ";
  tmp += test;
  tmp += ", one for me.";
  return tmp;
}
} // namespace two_fer
