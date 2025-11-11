#include "run_length_encoding.h"

#include <cctype>
#include <string>
#include <vector>

namespace run_length_encoding {

const std::string encode(std::string_view const &in1) {
  std::vector<std::pair<char, int>> data{};
  for (const auto &e : in1) {
    if (data.empty()) {
      data.push_back({e, 1});
    } else {
      if (data[data.size() - 1].first == e) {
        data[data.size() - 1].second++;
      } else {
        data.push_back({e, 1});
      }
    }
  }

  std::string ret{};
  for (auto const &e : data) {
    if (e.second == 1) {
      ret += e.first;
    } else {
      ret += std::to_string(e.second);
      ret += e.first;
    }
  }
  return ret;
}

const std::string decode(std::string_view const &in1) {
  std::string num{};
  std::string ret{};
  for (auto const &e : in1) {
    if (std::isdigit(e)) {
      num += e;
    } else {
      int count = 0;
      if (num.size() != 0) {
        count = std::stoi(num);
        num.clear();
        for (; count > 0; count--) {
          ret += e;
        }
      } else {
        ret += e;
      }
    }
  }
  return ret;
}
}  // namespace run_length_encoding
