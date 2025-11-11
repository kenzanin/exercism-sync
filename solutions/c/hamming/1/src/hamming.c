#include "hamming.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>

int compute(const char *lhs, const char *rhs) {
  if (*lhs == '\0' && *rhs == '\0')
    return 0;

  if (strlen(lhs) != strlen(rhs))
    return -1;

  int i = 0;
  int ii = 0;
  for (i = 0; i < (int)strlen(lhs); i++) {
    if (lhs[i] != rhs[i])
      ii++;
  }
  return ii;
}