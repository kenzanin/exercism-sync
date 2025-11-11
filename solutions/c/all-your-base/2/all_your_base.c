#include "all_your_base.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

size_t rebase(int8_t *digit, int16_t base, int16_t outputBase,
              size_t inputLenght) {
  size_t result = 0;
  if (base == 1 || outputBase <= 1 || inputLenght == 0)
    return 0;

  for (int i = 0; i < (int)inputLenght; i++) {
    int tmp = digit[(inputLenght - 1) - i];
    if (tmp >= base || tmp < 0)
      return 0;
    result += tmp * pow(base, i);
  }

  int ii = 0;
  for (int i = result; i > 0 || i == outputBase; i = i / outputBase) {
    digit[ii] = i % outputBase;
    ii++;
  }

  // reverse
  int iii = ii - 1;
  for (int i = 0; i < ii / 2; i++) {
    int8_t tmp = digit[iii];
    digit[iii] = digit[i];
    digit[i] = tmp;
    iii--;
  }

  return ii == 0 ? 1 : ii;
}
