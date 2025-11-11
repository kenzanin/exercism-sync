#include "acronym.h"
#include "ctype.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>

char *abbreviate(const char *phrase) {
  if (!phrase || !strlen(phrase))
    return NULL;

  char *tmp01 = calloc(strlen(phrase), sizeof(char));
  char *result = calloc(100, sizeof(char));
  strcpy(tmp01, phrase); // NOLINT

  for (size_t i = 0; i < strlen(tmp01); i++) {
    if (tmp01[i] == '-') {
      tmp01[i] = ' ';
    }
  }

  char *tmp02 = strtok(tmp01, " "); // NOLINT
  while (tmp02) {
    for (size_t i = 0; i < strlen(tmp02); i++) {
      if (isalpha(tmp02[i])) {
        // snprintf(result + strlen(result), 2, "%c", toupper(tmp02[i])); //
        // NOLINT
        char tmp03[2] = {0};
        tmp03[0] = toupper(tmp02[i]);
        strcpy(result + strlen(result), tmp03); // NOLINT
        break;
      }
    }
    tmp02 = strtok(NULL, " "); // NOLINT
  }

  char *ret = calloc(strlen(result), sizeof(char));
  strcpy(ret, result);

  free(result);
  free(tmp01);
  return ret;
}
