#include "nucleotide_count.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *count(const char *dna_strand) {
  char *result = calloc(30, sizeof(char));
  int dna[4] = {0};
  for (size_t i = 0; i < strlen(dna_strand); i++) {
    switch (dna_strand[i]) {
    case 'A':
      dna[0]++;
      break;
    case 'C':
      dna[1]++;
      break;
    case 'G':
      dna[2]++;
      break;
    case 'T':
      dna[3]++;
      break;
    default:
      return result;
    }
  }

  snprintf(result, 30, "A:%d C:%d G:%d T:%d", dna[0], dna[1], dna[2], dna[3]);
  return result;
}
