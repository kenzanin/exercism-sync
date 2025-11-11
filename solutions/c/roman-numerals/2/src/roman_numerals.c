#include "roman_numerals.h"
#include <stdlib.h>
#include <string.h>

void addRoman(char *result, int charNum, char *roman) {
  result = realloc(result, charNum * sizeof(char));
  strcat(result, roman);
}

char *to_roman_numeral(unsigned int number) {
  char *result = {0};
  result = (char *)calloc(sizeof(char), 1);
  int charNum = 1;
  char *roman = {0};
  while (number > 0) {
    if (number >= 1000) {
      charNum += 1;
      number -= 1000;
      roman = "M";
    } else if (number >= 900) {
      charNum += 2;
      number -= 900;
      roman = "CM";
    } else if (number >= 500) {
      charNum += 1;
      number -= 500;
      roman = "D";
    } else if (number >= 400) {
      charNum += 2;
      number -= 400;
      roman = "CD";
    } else if (number >= 100) {
      charNum += 1;
      number -= 100;
      roman = "C";
    } else if (number >= 90) {
      charNum += 2;
      number -= 90;
      roman = "XC";
    } else if (number >= 50) {
      charNum += 1;
      number -= 50;
      roman = "L";
    } else if (number >= 40) {
      charNum += 2;
      number -= 40;
      roman = "XL";
    } else if (number >= 10) {
      charNum += 1;
      number -= 10;
      roman = "X";
    } else if (number >= 9) {
      charNum += 2;
      number -= 9;
      roman = "IX";
    } else if (number >= 6) {
      charNum += 2;
      number -= 6;
      roman = "VI";
    } else if (number >= 5) {
      charNum += 1;
      number -= 5;
      roman = "V";
    } else if (number >= 4) {
      charNum += 2;
      number -= 4;
      roman = "IV";
    } else if (number >= 1) {
      number -= 1;
      charNum += 1;
      roman = "I";
    }
    addRoman(result, charNum, roman);
  }

  return result;
}
