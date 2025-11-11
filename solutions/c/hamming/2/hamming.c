#include "hamming.h"
#include "string.h"
#include <stddef.h>

int compute(const char *lhs, const char *rhs) {
  if (strlen(lhs) != strlen(rhs) || ((strlen(lhs) == 0) ^ (strlen(rhs) == 0))) {
    return -1;
  }

  int result = 0;
  for (size_t i = 0; i < strlen(lhs); i++) {
    result += (lhs[i] == rhs[i] ? 0 : 1);
  }
  return result;
}
