#include "diamond.h"
#include "stdlib.h"
#include "string.h"
#include <stdio.h>

char **make_diamond(const char letter) {
  int size = (letter - 'A') * 2 + 1;
  int center = size / 2;
  char **result = calloc(size, sizeof(char *));
  for (int i = 0; i < size; i++) {
    result[i] = calloc(size + 1, sizeof(char));
    memset(result[i], ' ', size);
  }

  for (int i = 0, j; i <= center; i++) {
    char c = 'A' + i;
    j = size - i - 1;
    result[i][center - i] = c;
    result[i][center + i] = c;
    result[j][center - i] = c;
    result[j][center + i] = c;
  }
  return result;
}
void free_diamond(char **diamond) {
  free(diamond);
  diamond = NULL;
}
