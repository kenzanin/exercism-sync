#include "binary.h"

int convert(const char *input) {
  int i = 0;
  int result = 0;
  for (i = 0; input[i] != '\0'; i++) {
    if (input[i] > '1')
      return INVALID;
    result <<= 1;
    if (input[i] == '1') {
      result |= 1;
    }
  }
  return result;
}
