#pragma once

#include <string>
#include <vector>
namespace resistor_color {
const auto cc =
    std::vector<std::string>{"black", "brown", "red",    "orange", "yellow",
                             "green", "blue",  "violet", "grey",   "white"};
int color_code(std::string const &in1);
std::vector<std::string> colors();
} // namespace resistor_color
