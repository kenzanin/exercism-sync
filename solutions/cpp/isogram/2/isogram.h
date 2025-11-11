#if !defined(ISOGRAM_H)
#define ISOGRAM_H
#include "iostream"
#include "string"
#include <cctype>
#include <vector>

namespace isogram {
bool is_isogram(std::string const &test);
} // namespace isogram

#endif // ISOGRAM_H