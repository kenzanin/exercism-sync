#include "protein_translation.h"
#include <string.h>
protein_t find(const char *in);
protein_t find(const char *in) {
  if (memcmp(in, "AUG", 3) == 0)
    return Methionine;
  else if (memcmp(in, "UUU", 3) == 0 || memcmp(in, "UUC", 3) == 0)
    return Phenylalanine;
  else if (memcmp(in, "UUA", 3) == 0 || memcmp(in, "UUG", 3) == 0)
    return Leucine;
  else if (memcmp(in, "UCU", 3) == 0 || memcmp(in, "UCC", 3) == 0 || memcmp(in, "UCA", 3) == 0 || memcmp(in, "UCG", 3) == 0)
    return Serine;
  else if (memcmp(in, "UAU", 3) == 0 || memcmp(in, "UAC", 3) == 0)
    return Tyrosine;
  else if (memcmp(in, "UGU", 3) == 0 || memcmp(in, "UGC", 3) == 0)
    return Cysteine;
  else if (memcmp(in, "UGG", 3) == 0)
    return Tryptophan;
  else if (memcmp(in, "UAA", 3) == 0 || memcmp(in, "UAG", 3) == 0 || memcmp(in, "UGA", 3) == 0)
    return STOP;
  else
    return NONVALID;
}

proteins_t proteins(const char *const rna) {
  proteins_t data = {.valid = true, .count = 0};
  size_t ii = 0;
  size_t len = strlen(rna);
  for (; ii < len; ii += 3) {
    protein_t valid = find(rna + ii);
    if (valid == STOP) {
      break;
    } else if (valid == NONVALID) {
      data.valid = false;
      continue;
    }
    data.proteins[data.count] = valid;
    data.count++;
  }
  if (ii % 3 != 0)
    data.valid = false;
  return data;
}
