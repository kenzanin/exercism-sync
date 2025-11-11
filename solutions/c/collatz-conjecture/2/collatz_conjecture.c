#include "collatz_conjecture.h"

int steps(int start) {
  if (start <= 0)
    return ERROR_VALUE;
  int result = 0;
  while (start > 1) {
    start = ((start & 1) == 1) ? start * 3 + 1 : start / 2;
    result++;
  }
  return result;
}
