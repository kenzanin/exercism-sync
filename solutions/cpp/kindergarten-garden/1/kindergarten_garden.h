#pragma once

#include "string"
#include <array>

namespace kindergarten_garden {
enum Plants { clover, grass, violets, radishes };
std::array<Plants, 4> plants(const std::string &in1, const std::string &in2);
} // namespace kindergarten_garden
