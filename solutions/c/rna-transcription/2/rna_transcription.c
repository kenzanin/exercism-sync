#include "rna_transcription.h"
#include "string.h"
#include <stdlib.h>

char *to_rna(const char *dna) {
  char *result = calloc(strlen(dna), sizeof(char));

  for (size_t i = 0; i < strlen(dna); i++) {
    switch (dna[i]) {
    case 'G':
      result[i] = 'C';
      break;
    case 'C':
      result[i] = 'G';
      break;
    case 'T':
      result[i] = 'A';
      break;
    case 'A':
      result[i] = 'U';
      break;
    default:
      break;
    }
  }
  return result;
}
