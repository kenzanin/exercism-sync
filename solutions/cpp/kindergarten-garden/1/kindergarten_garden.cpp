#include "kindergarten_garden.h"
#include <array>
#include <cstddef>
#include <string>
#include <string_view>
#include <unordered_map>

namespace kindergarten_garden {
const std::unordered_map<std::string_view, const size_t> start{
    {"Alice", 0},   {"Bob", 2},     {"Charlie", 4},  {"David", 6},
    {"Eve", 8},     {"Fred", 10},   {"Ginny", 12},   {"Harriet", 14},
    {"Ileana", 16}, {"Joseph", 18}, {"Kincaid", 20}, {"Larry", 22}};
const std::unordered_map<char, Plants> getPlants{{'C', Plants::clover},
                                                 {'G', Plants::grass},
                                                 {'V', Plants::violets},
                                                 {'R', Plants::radishes}};

std::array<Plants, 4> plants(const std::string &in1, const std::string &in2) {
  const size_t offset = in1.find('\n') + 1;
  std::array<Plants, 4> data{};
  for (size_t i = 0; i < 2; i++) {
    data[i] = getPlants.at(in1[start.at(in2) + i]);
    data[i + 2] = getPlants.at(in1[start.at(in2) + i + offset]);
  }
  return data;
}
} // namespace kindergarten_garden
