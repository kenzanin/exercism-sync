#include "perfect_numbers.h"

kind classify_number(int n) {
  if (n < 1)
    return -1;
  int index = (int)sqrt(n);
  int count = -n;
  if (index * index == n) {
    count -= index;
  }

  for (; index > 0; index--) {
    if (!(n % index)) {
      count += index;
      count += (n / index);
    }
  }

  if (count == n)
    return PERFECT_NUMBER;
  else if (count > n)
    return ABUNDANT_NUMBER;
  else
    return DEFICIENT_NUMBER;
}