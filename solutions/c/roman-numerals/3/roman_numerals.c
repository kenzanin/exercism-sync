#include "roman_numerals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_roman_numeral(unsigned int number) {
  char *result = calloc(10, sizeof(char));

  int i = number;
  while (i > 0) {
    if (i > 0 && i < 4) {
      sprintf(result + strlen(result), "%.*s", i, "III");
      i = 0;
    } else if (i == 4) {
      strcat(result + strlen(result), "IV");
      i = 0;
    } else if (i == 5) {
      strcat(result + strlen(result), "V");
      i = 0;
    } else if (i >= 6 && i <= 8) {
      sprintf(result + strlen(result), "%.*s", i - 4, "VIII");
      i = 0;
    } else if (i == 9) {
      strcat(result + strlen(result), "IX");
      i = 0;
    } else if (i >= 10 && i < 40) {
      sprintf(result + strlen(result), "%.*s", (i / 10), "XXX");
      i %= 10;
    } else if (i >= 40 && i < 50) {
      strcat(result + strlen(result), "XL");
      i -= 40;
    } else if (i >= 50 && i < 90) {
      strcat(result + strlen(result), "L");
      i -= 50;
    } else if (i >= 90 && i < 100) {
      strcat(result + strlen(result), "XC");
      i -= 90;
    } else if (i >= 100 && i < 400) {
      strcat(result + strlen(result), "C");
      i -= 100;
    } else if (i >= 400 && i < 500) {
      strcat(result + strlen(result), "CD");
      i -= 400;
    } else if (i >= 500 && i < 900) {
      strcat(result + strlen(result), "D");
      i -= 500;
    } else if (i >= 900 && i < 1000) {
      strcat(result + strlen(result), "CM");
      i -= 900;
    } else if (i >= 1000) {
      strcat(result + strlen(result), "M");
      i -= 1000;
    }
  }
  return result;
}
