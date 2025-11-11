#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
  if (limit < 2) return 0;
  if (limit == 2) {
    primes[0] = 2;
    return 1;
  }

  uint32_t tmp[limit + 1];
  for (uint32_t i = 0; i <= limit; i++) {
    tmp[i] = i;
  }

  uint32_t index = 0;
  for (uint32_t i = 2; i <= limit; i++) {
    if (tmp[i] == 6666) continue;
    primes[index] = i;
    index++;
    for (uint32_t ii = i; ii <= limit; ii += i) {
      tmp[ii] = 6666;
    }
  }
  return index < max_primes ? index : max_primes;
}