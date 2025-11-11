#include "series.h"
#include <stdlib.h>
#include <string.h>

slices_t slices(char *input_text, unsigned int substring_length) {
  slices_t tmp = {0};
  unsigned int inLen = strlen(input_text);
  if (inLen == 0 || substring_length == 0)
    return tmp;
  tmp.substring_count = inLen - substring_length + 1;
  tmp.substring = (char **)calloc(sizeof(char *), tmp.substring_count);
  int i = 0;
  for (; i <= (int)(inLen - substring_length); i++) {
    tmp.substring[i] = calloc(sizeof(char), substring_length);
    strncpy(tmp.substring[i], input_text + i, substring_length);
  }
  return tmp;
}