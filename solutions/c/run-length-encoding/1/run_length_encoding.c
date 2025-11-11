#include "run_length_encoding.h"
#include "ctype.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

char *encode(const char *text) {
  char *result = calloc(20, sizeof(char));

  struct _tmp01 {
    char c;
    int count;
  } tmp01 = {0};
  char oldc = 0;
  for (size_t i = 0; i < strlen(text); i++) {
    tmp01.c = text[i];
    if (oldc == text[i]) {
      tmp01.count++;
    }
    if (text[i] != text[i + 1]) {
      if (tmp01.count > 0)
        sprintf(result + strlen(result), "%d", tmp01.count + 1);
      sprintf(result + strlen(result), "%c", tmp01.c);
      tmp01.count = 0;
      tmp01.c = 0;
    }
    oldc = text[i];
  }
  return result;
}

char *decode(const char *data) {
  char *result = calloc(100, sizeof(char));

  char tmp01[4] = {0};
  int count = 0;
  for (size_t i = 0; i < strlen(data); i++) {
    if (isdigit(data[i])) {
      tmp01[count] = data[i];
      count++;
    } else {
      if (count > 0) {
        sscanf(tmp01, "%d", &count);
        for (int ii = 0; ii < count; ii++) {
          result[strlen(result)] = data[i];
        }
        count = 0;
        memset(tmp01, 0, sizeof(tmp01) / sizeof(tmp01[0]));
      } else {
        result[strlen(result)] = data[i];
      }
    }
  }
  return result;
}
