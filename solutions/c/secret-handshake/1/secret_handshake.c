#include "secret_handshake.h"
#include <stdlib.h>
#include <string.h>

const char **commands(size_t number) {
  char tmp[4][20] = {0};

  int num = 0;

  if ((number & 1) != 0) {
    strcpy(tmp[num], "wink");
    num++;
  }

  if ((number & 2) != 0) {
    strcpy(tmp[num], "double blink");
    num++;
  }

  if ((number & 4) != 0) {
    strcpy(tmp[num], "close your eyes");
    num++;
  }

  if ((number & 8) != 0) {
    strcpy(tmp[num], "jump");
    num++;
  }

  // reverse
  if ((number & 16) != 0) {
    char tmp2[20] = {0};
    for (int i = 0; i < num / 2; i++) {
      memset(tmp2, 0, 20);
      strcpy(tmp2, tmp[i]);
      memset(tmp[i], 0, 20);
      strcpy(tmp[i], tmp[num - (i + 1)]);
      memset(tmp[num - (i + 1)], 0, 20);
      strcpy(tmp[num - (i + 1)], tmp2);
    }
  }

  char **result = (char **)calloc(num, sizeof(char *));
  for (int i = 0; i < num; i++) {
    result[i] = (char *)calloc(strlen(tmp[i]), sizeof(char));
    strcpy(result[i], tmp[i]);
  }
  return (const char **)result;
}
