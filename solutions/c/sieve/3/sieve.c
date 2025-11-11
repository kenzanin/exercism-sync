#include "sieve.h"

#include <string.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
  if (limit < 2) return 0;
  if (limit == 2) {
    primes[0] = 2;
    return 1;
  }

  int8_t tmp[limit + 1];
  memset(tmp, 0, sizeof(int8_t) * limit + 1);

  uint32_t index = 0;
  for (uint32_t i = 2; i <= limit; i++) {
    if (tmp[i] == -1) continue;
    primes[index] = i;
    index++;
    for (uint32_t ii = i; ii <= limit; ii += i) {
      tmp[ii] = -1;
    }
  }
  return index < max_primes ? index : max_primes;
}