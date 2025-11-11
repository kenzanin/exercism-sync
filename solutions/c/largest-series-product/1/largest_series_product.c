#include "largest_series_product.h"
#include "ctype.h"
#include <string.h>

int64_t largest_series_product(char *digits, size_t span) {
  if (strlen(digits) < span || span == (size_t)-1) // NOLINT
    return -1;
  if (strlen(digits) == 0 || span == 0)
    return 1;

  int64_t result_old = 0;
  int64_t result_new = 0;
  for (size_t i = (span - 1); i < strlen(digits); i++) {
    for (size_t ii = i - (span - 1); ii <= i; ii++) {
      if (!isdigit(digits[ii]))
        return -1;
      int tmp = digits[ii] - '0';
      result_new = (ii == (i - (span - 1))) ? tmp : result_new * tmp;
    }
    result_old = (result_old < result_new) ? result_new : result_old;
  }
  return result_old;
}
