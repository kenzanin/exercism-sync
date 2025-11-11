#include "prime_factors.h"
#include "math.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]) {
  int count = 0;
  while (n % 2 == 0) {
    factors[count] = 2;
    count++;
    n /= 2;
  }

  for (size_t i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      factors[count] = i;
      count++;
      n = n / i;
    }
  }
  if (n > 2) {
    factors[count] = n;
    count++;
  }
  return count;
}
