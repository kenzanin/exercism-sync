#include "yacht.h"

#include <algorithm>
#include <any>
#include <iterator>
#include <numeric>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace yacht {
int score(const std::vector<int> &in1, std::string_view const &in2) {
  auto one_to_six = [&in1](int x) -> int {
    return std::count(in1.begin(), in1.end(), x) * x;
  };
  auto yacht = [&in1]() -> int {
    return std::equal(in1.begin() + 1, in1.end(), in1.begin()) ? 50 : 0;
  };
  auto full_house = [&in1]() -> int {
    auto var01 = std::unordered_map<int, int>{};
    for (const auto &e : in1) {
      var01[e]++;
    }
    if (var01.size() != 2) {
      return 0;
    } else if (var01.begin()->second > 3 ||
               std::next(var01.begin())->second > 3) {
      return 0;
    }
    return std::accumulate(in1.begin(), in1.end(), 0);
  };
  auto four_of_a_kind = [&in1]() -> int {
    auto var01 = std::unordered_map<int, int>{};
    for (const auto &e : in1) {
      var01[e]++;
    }
    if (var01.size() == 1) {
      return var01.begin()->first * 4;
    } else if (var01.size() > 2) {
      return 0;
    } else if (var01.begin()->second == 4) {
      return var01.begin()->first * 4;
    } else if (std::next(var01.begin())->second == 4) {
      return std::next(var01.begin())->first * 4;
    }
    return 0;
  };
  auto straight = [&in1](const std::vector<int> &x) -> int {
    auto y = std::vector<int>{in1};
    std::sort(y.begin(), y.end());
    return y == x ? 30 : 0;
  };
  auto choice = [&in1]() -> int {
    return std::accumulate(in1.begin(), in1.end(), 0);
  };

  const auto func_map = std::unordered_map<std::string_view, std::any>{
      {"ones", one_to_six(1)},                        //
      {"twos", one_to_six(2)},                        //
      {"threes", one_to_six(3)},                      //
      {"fours", one_to_six(4)},                       //
      {"fives", one_to_six(5)},                       //
      {"sixes", one_to_six(6)},                       //
      {"yacht", yacht()},                             //
      {"full house", full_house()},                   //
      {"four of a kind", four_of_a_kind()},           //
      {"little straight", straight({1, 2, 3, 4, 5})}, //
      {"big straight", straight({2, 3, 4, 5, 6})},    //
      {"choice", choice()}                            //
  };

  int res = std::any_cast<int>(func_map.at(in2));
  return res;
}
} // namespace yacht
