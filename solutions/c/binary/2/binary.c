#include "binary.h"
#include "math.h"
#include "string.h"

int convert(const char *input) {
  int result = 0;
  int count = 0;
  for (size_t i = strlen(input); i > 0; i--) {
    if ((input[i - 1] - '0') > 1)
      return -1;
    result += pow(2, count) * (input[i - 1] - '0');
    count++;
  }
  return result;
}
