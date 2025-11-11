#include "luhn.h"
#include <bits/stdint-uintn.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

bool luhn(const char *num) {
  if (strlen(num) == 1)
    return false;
  uint8_t ii = 0;
  int sum = 0;
  char *items = (char *)calloc(strlen(num), sizeof(char));

  for (size_t i = 0; i < strlen(num); i++) {
    if (num[i] >= '0' && num[i] <= '9') {
      items[ii] = num[i];
      ii++;
    } else if (num[i] == ' ') {
      continue;
    } else {
      return false;
    }
  }
  if (strlen(items) <= 1)
    return false;
  ii = 0;
  for (int i = (int)strlen(items) - 1; i >= 0; --i) {
    items[i] = items[i] - '0';
    if (ii == 1) {
      int tmp = items[i] * 2;
      items[i] = tmp > 9 ? tmp - 9 : tmp;
      ii = 0;
    } else {
      ii++;
    }
    sum += items[i];
  }
  return (sum % 10) == 0;
}
