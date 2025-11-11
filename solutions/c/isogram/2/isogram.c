#include "isogram.h"
#include "ctype.h"
#include "string.h"
#include <stdbool.h>
#include <stddef.h>

bool is_isogram(const char phrase[]) {
  if (phrase == NULL)
    return false;
  if (strlen(phrase) == 0)
    return true;

  for (size_t i = 0; i < strlen(phrase) - 1; i++) {
    if (!isalpha(phrase[i]))
      continue;
    for (size_t ii = i + 1; ii < strlen(phrase); ii++) {
      if (!isalpha(phrase[ii]))
        continue;
      if (tolower(phrase[i]) == tolower(phrase[ii]))
        return false;
    }
  }
  return true;
}
