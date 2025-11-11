#include <iterator>
#if !defined(SIEVE_H)
#define SIEVE_H

#include <unordered_map>
#include <vector>

namespace sieve {
std::vector<int> primes(std::size_t);
} // namespace sieve

#endif // SIEVE_H