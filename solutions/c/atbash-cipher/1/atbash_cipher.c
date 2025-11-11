#include "atbash_cipher.h"
#include "ctype.h"
#include "stdint.h"
#include "string.h"
#include <stdlib.h>

char *thomasTheTank_(uint8_t dir, const char *input);

char *thomasTheTank_(uint8_t dir, const char *input) {
  char *result = calloc(100, sizeof(char));

  size_t count = 0;
  uint8_t count2 = 0;
  for (size_t i = 0; i < strlen(input); i++) {
    char ii = tolower(input[i]);
    if (!isalnum(ii))
      continue;

    result[count] = (isalpha(ii) ? ('z' - ii) + 'a' : ii);
    count++;
    count2++;
    if (count2 % 5 == 0 && (i + 1) < strlen(input) - 1 && dir == 0) {
      result[count++] = ' ';
    }
  }
  return result;
}

char *atbash_encode(const char *input) { return thomasTheTank_(0, input); }

char *atbash_decode(const char *input) { return thomasTheTank_(1, input); }
