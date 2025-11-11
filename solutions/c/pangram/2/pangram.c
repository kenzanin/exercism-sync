#include "pangram.h"
#include "ctype.h"
#include <stdbool.h>
#include <string.h>

bool is_pangram(const char *sentence) {
  if (!sentence || strlen(sentence) == 0)
    return false;
  const char atoz[] = {"abcdefghijklmnopqrstuvwxyz"};
  for (size_t i = 0; i < strlen(atoz); i++) {
    for (size_t ii = 0; ii < strlen(sentence); ii++) {
      if (atoz[i] == tolower(sentence[ii])) {
        break;
      }
      if (ii == strlen(sentence) - 1)
        return false;
    }
  }
  return true;
}
