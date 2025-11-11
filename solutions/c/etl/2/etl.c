#include "etl.h"
#include "ctype.h"
#include "string.h"
#include <stdlib.h>

int compar(const void *a, const void *b);

int compar(const void *a, const void *b) {
  new_map aa = *(new_map *)a;
  new_map bb = *(new_map *)b;
  return aa.key - bb.key;
}

int convert(const legacy_map *input, const size_t input_len, new_map **output) {
  int ii = 0;
  int count = 0;
  *output = calloc(1, sizeof(new_map));
  for (int i = 0; i < (int)input_len; i++) {
    legacy_map tmp = input[i];
    for (ii = 0; ii < (int)strlen(tmp.keys); ii++) {
      new_map tmp02 = {tolower(tmp.keys[ii]), tmp.value};
      *output = realloc(*output, sizeof(new_map) * (count + 1));
      *(*output + count) = tmp02;
      count++;
    }
  }
  qsort(*output, count, sizeof(new_map), compar);
  return count;
}
