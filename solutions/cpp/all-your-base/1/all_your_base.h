#if !defined(ALL_YOUR_BASE_H)
#define ALL_YOUR_BASE_H
#include <vector>

namespace all_your_base {
std::vector<unsigned int>
convert(int base_in, const std::vector<unsigned int> &input, int base_out);
} // namespace all_your_base

#endif // ALL_YOUR_BASE_H