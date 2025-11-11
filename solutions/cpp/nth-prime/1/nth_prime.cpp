#include "nth_prime.h"

#include <cmath>
#include <cstddef>

namespace nth_prime {
int nth(int n) {
  /*
  uint8_t isPrime(uint32_t n) {
    for (uint32_t i = 3; i <= sqrtf(n); i += 2) {
      if (n % i == 0)
        return 0;
    }
    return 1;
  }
  */
  auto is_prime = [](std::size_t n) -> bool {
    for (std::size_t i = 3; i <= std::sqrt(n); i += 2) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  };

  std::size_t up = 11;
  n -=4;
  while(n>0){
    if(is_prime(up)){
      n--;      
    }
    up+=2;
  }

  return up-2;
}
}  // namespace nth_prime
