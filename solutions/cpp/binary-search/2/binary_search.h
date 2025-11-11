#if !defined(BINARY_SEARCH_H)
#define BINARY_SEARCH_H
#include <cstddef>
#include <stdexcept>
#include <vector>

namespace binary_search {
int find(std::vector<int> const &data, int n);
} // namespace binary_search

#endif // BINARY_SEARCH_H