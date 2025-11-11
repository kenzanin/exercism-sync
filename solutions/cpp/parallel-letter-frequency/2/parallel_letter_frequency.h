#if !defined(PARALLEL_LETTER_FREQUENCY_H)
#define PARALLEL_LETTER_FREQUENCY_H
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace parallel_letter_frequency {
std::unordered_map<char,int> frequency(std::vector<std::string_view> const &in);
}

#endif
