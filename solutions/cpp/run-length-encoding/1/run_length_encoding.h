#pragma once
#include <string_view>

namespace run_length_encoding {
const std::string encode(std::string_view const &);
const std::string decode(std::string_view const &);
}  // namespace run_length_encoding
