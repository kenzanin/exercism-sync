#include "series.h"
#include "string.h"
#include <stdlib.h>

slices_t slices(char *input_text, unsigned int substring_length) {
  if (strlen(input_text) < substring_length || substring_length == 0) {
    slices_t tmp02 = {0};
    return tmp02;
  }

  char **tmp = calloc(100, sizeof(char *));
  unsigned int count = 0;
  for (count = 0; count <= strlen(input_text) - substring_length; count++) {
    tmp[count] = calloc(substring_length + 1, sizeof(char));
    memset(tmp[count], 0, sizeof(char) * substring_length);
    for (unsigned int ii = count; ii < substring_length + count; ii++) {
      char iii[2] = {0};
      iii[0] = input_text[ii];
      strcpy(tmp[count] + strlen(tmp[count]), iii); // NOLINT
    }
  }

  slices_t result;
  result.substring = tmp;
  result.substring_count = count;
  return result;
}
