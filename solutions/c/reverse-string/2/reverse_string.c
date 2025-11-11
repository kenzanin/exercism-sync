#include "reverse_string.h"

#include <stdlib.h>
#include <string.h>

char *reverse(const char *value) {
  char *ret = (char *)calloc(strlen(value), sizeof(char));
  for (int i = strlen(value) - 1; i >= 0; i--) {
    const int index = (strlen(value) - 1) - i;
    ret[index] = value[i];
  }

  return ret;
}