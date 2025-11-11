#include "scrabble_score.h"

#include "string.h"
#include <ctype.h>

int check(char a);

int check(char a) {
  a = tolower(a);
  switch (a) {
  case 'd':
  case 'g':
    return 2;
  case 'b':
  case 'c':
  case 'm':
  case 'p':
    return 3;
  case 'f':
  case 'h':
  case 'v':
  case 'w':
  case 'y':
    return 4;
  case 'k':
    return 5;
  case 'j':
  case 'x':
    return 8;
  case 'q':
  case 'z':
    return 10;
  default:
    break;
  }
  return 1;
}

unsigned int score(const char *word) {
  unsigned int score = 0;
  for (size_t i = 0; i < strlen(word); i++) {
    score += check(word[i]);
  }
  return score;
}
