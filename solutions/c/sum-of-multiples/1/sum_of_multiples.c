#include "sum_of_multiples.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit) {
  int *items = (int *)calloc(1, sizeof(int));
  int iii = 0;

  for (int i = 0; i < (int)number_of_factors; ++i) {
    if (factors[i] == 0)
      continue;
    int tmp = 0;
    int ii = 0;
    do {
      tmp = factors[i] * (ii + 1);
      if (tmp >= (int)limit)
        break;
      items = realloc(items, (iii * sizeof(int)) + sizeof(int));
      items[iii] = tmp;
      iii++;
      ii++;
    } while (tmp < (int)limit);
  }

  // zero-ing duplicate
  for (int i = 0; i < iii - 1; i++) {
    for (int ii = i + 1; ii < iii; ii++) {
      if (items[i] == items[ii]) {
        items[ii] = 0;
      }
    }
  }

  unsigned int result = 0;
  for (int i = 0; i < iii; i++) {
    result += items[i];
  }

  free(items);
  return result;
}
