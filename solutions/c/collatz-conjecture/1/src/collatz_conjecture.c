#include "collatz_conjecture.h"

int steps(int start) {
  if (start < 1)
    return ERROR_VALUE;

  int step = 0;
  while (start > 1) {
    if (start & 1) {
      start = 3 * start + 1;
    } else {
      start /= 2;
    }
    step++;
  }
  return step;
}