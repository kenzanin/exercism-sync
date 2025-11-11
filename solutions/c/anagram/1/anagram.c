#include "anagram.h"
#include <stdlib.h>
#include <string.h>

int strSort(const void *a, const void *b);
void strLow(char *a);

int strSort(const void *a, const void *b) {
  char aa = *(const char *)a;
  char bb = *(const char *)b;
  if (aa > bb)
    return 1;
  else
    return -1;

  return 0;
}

void strLow(char *a) {
  for (size_t i = 0; i < strlen(a); ++i) {
    a[i] |= 0x20;
  }
}

void find_anagrams(const char *subject, struct candidates *candidates) {
  char *word = (char *)calloc(strlen(subject), sizeof(char));
  strcpy(word, subject);
  strLow(word);
  for (size_t i = 0; i < candidates->count; i++) {
    char *word2 =
        (char *)calloc(strlen(candidates->candidate[i].word), sizeof(char));
    strcpy(word2, candidates->candidate[i].word);
    strLow(word2);
    if (strcmp(word, word2) == 0) {
      candidates->candidate[i].is_anagram = NOT_ANAGRAM;
      continue;
    }
    qsort(word, strlen(subject), sizeof(char), strSort);
    qsort(word2, strlen(word2), sizeof(char), strSort);
    if (strcmp(word, word2) == 0) {
      candidates->candidate[i].is_anagram = IS_ANAGRAM;
    } else {
      candidates->candidate[i].is_anagram = NOT_ANAGRAM;
    }
    free(word2);
  }
  free(word);
}
