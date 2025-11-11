#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H
#include <algorithm>
#include <cctype>
#include <map>
#include <sstream>
#include <string>

namespace word_count {
std::map<std::string, int> words(const std::string &str);
} // namespace word_count

#endif // WORD_COUNT_H