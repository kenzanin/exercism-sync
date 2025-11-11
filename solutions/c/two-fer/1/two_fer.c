#include "two_fer.h"
#include "string.h"
#include <stdio.h>

void two_fer(char *buffer, const char *name) {
  char result[100] = {"One for %s, one for me."};
  char tmp[10] = {0};

  if (name == NULL) {
    snprintf(tmp, sizeof(tmp), "you");
  } else {
    snprintf(tmp, sizeof(tmp), "%s", name);
  }
  snprintf(buffer, sizeof(result), result, tmp);
}
