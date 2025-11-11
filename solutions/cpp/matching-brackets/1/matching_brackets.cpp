#include "matching_brackets.h"
#include "stack"
#include <cctype>
#include <vector>

namespace matching_brackets {
bool check(std::string test) {
  char ch{};
  std::stack<char> s{};
  for (auto c : test) {
    if (c == '{' || c == '[' || c == '(') {
      s.push(c);
      continue;
    } else if (c == '}' || c == ']' || c == ')') {
      if (s.empty())
        return false;
      switch (c) {
      case ')': {
        ch = s.top();
        s.pop();
        if (ch == '(')
          continue;
        else
          return false;
      }
      case ']': {
        ch = s.top();
        s.pop();
        if (ch == '[')
          continue;
        else
          return false;
      }
      case '}': {
        ch = s.top();
        s.pop();
        if (ch == '{')
          continue;
        else
          return false;
      }
      default:
        continue;
      }
    }
  }
  if (s.size() > 1)
    return false;
  return true;
}
} // namespace matching_brackets
