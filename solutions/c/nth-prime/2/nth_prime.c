#include "nth_prime.h"
#include "math.h"

uint8_t isPrime(uint32_t n);
uint8_t isPrime(uint32_t n) {
  for (uint32_t i = 3; i <= sqrtf(n); i += 2) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

uint32_t nth(uint32_t n) {
  switch (n) {
  case 0:
    return 0;
  case 1:
    return 2;
  case 2:
    return 3;
  case 3:
    return 5;
  case 4:
    return 7;
  default:
    break;
  }

  int up = 11;
  n -= 4;
  while (n > 0) {
    if (isPrime(up)) {
      n--;
    }
    up += 2;
  }
  return up-2;
}
