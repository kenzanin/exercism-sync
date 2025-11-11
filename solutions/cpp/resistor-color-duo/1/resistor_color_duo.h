#pragma once
#include <string>
#include <vector>

namespace resistor_color_duo {
const auto cc =
    std::vector<std::string>{"black", "brown", "red",    "orange", "yellow",
                             "green", "blue",  "violet", "grey",   "white"};
int value(std::vector<std::string> in1);
} // namespace resistor_color_duo
