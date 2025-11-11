#include "phone_number.h"

#include "ctype.h"
#include "stdlib.h"
#include "string.h"

const char ERROR[] = {"0000000000"};
#define error()                                                                \
  {                                                                            \
    strcpy(result, ERROR);                                                     \
    return result;                                                             \
  }

char *phone_number_clean(const char *input) {
  char *result = calloc(strlen(input) <= 9 ? 9 : strlen(input), sizeof(char));

  size_t count = 0;
  for (size_t i = 0; i < strlen(input); i++) {
    if (input[i] >= '0' && input[i] <= '9') {
      result[count] = input[i];
      count++;
    }
    if (isalpha(input[i]) || input[i] == '@' || input[i] == ':' ||
        input[i] == '!') {
      error();
    }
  }

  // bad length
  if (count <= 9 || count > 11) {
    error();
  }

  // 11 digit
  if (count == 11) {
    if (result[0] != '1' || result[4] == '0' || result[4] == '1' ||
        result[1] == '0' || result[1] == '1')
      error();
  }

  // 10 digit
  if (count == 10) {
    if (result[0] == '1' || result[0] == '0' || result[3] == '0' ||
        result[3] == '1')
      error();
  }

  if (strlen(result) == 11) {
    memcpy(result, result + 1, strlen(result) - 1);
    result[strlen(result) - 1] = 0;
  }
  return result;
}
