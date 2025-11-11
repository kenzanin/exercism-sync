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
  while (number > 0) {
    if (number >= 1000) {
      charNum += 1;
      addRoman(result, charNum, "M");
      number -= 1000;
    } else if (number >= 900) {
      charNum += 2;
      addRoman(result, charNum, "CM");
      number -= 900;
    } else if (number >= 500) {
      charNum += 1;
      addRoman(result, charNum, "D");
      number -= 500;
    } else if (number >= 400) {
      charNum += 2;
      addRoman(result, charNum, "CD");
      number -= 400;
    } else if (number >= 100) {
      charNum += 1;
      addRoman(result, charNum, "C");
      number -= 100;
    } else if (number >= 90) {
      charNum += 2;
      addRoman(result, charNum, "XC");
      number -= 90;
    } else if (number >= 50) {
      charNum += 1;
      addRoman(result, charNum, "L");
      number -= 50;
    } else if (number >= 40) {
      charNum += 2;
      addRoman(result, charNum, "XL");
      number -= 40;
    } else if (number >= 10) {
      charNum += 1;
      addRoman(result, charNum, "X");
      number -= 10;
    } else if (number >= 9) {
      charNum += 2;
      addRoman(result, charNum, "IX");
      number -= 9;
    } else if (number >= 6) {
      charNum += 2;
      addRoman(result, charNum, "VI");
      number -= 6;
    } else if (number >= 5) {
      charNum += 1;
      addRoman(result, charNum, "V");
      number -= 5;
    } else if (number >= 4) {
      charNum += 2;
      addRoman(result, charNum, "IV");
      number -= 4;
    } else if (number >= 1) {
      addRoman(result, charNum++, "I");
      number -= 1;
    }
  }

  return result;
}
