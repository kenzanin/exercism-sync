#include <cstddef>
#include <string_view>
#if !defined(LARGEST_SERIES_PRODUCT_H)
#define LARGEST_SERIES_PRODUCT_H

#include <algorithm>
#include <string>

namespace largest_series_product {
std::size_t largest_product(std::string const &str, std::size_t len);
} // namespace largest_series_product

#endif // LARGEST_SERIES_PRODUCT_H