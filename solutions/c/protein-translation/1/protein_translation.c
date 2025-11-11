#include "protein_translation.h"
#include <stdbool.h>
#include <string.h>
protein_t find(const char *in);

protein_t find(const char *in) {
  switch (in[0]) {
  case 'A':
    switch (in[1]) {
    case 'U':
      return Methionine;
    }break;
  case 'U':
    switch (in[1]) {
    case 'U': {
      switch (in[2]) {
      case 'A':
      case 'G':
        return Leucine;
      case 'U':
      case 'C':
        return Phenylalanine;
      }
      break;
    }
    case 'C':
      return Serine;
    case 'A':
      switch (in[2]) {
      case 'C':
      case 'U':
        return Tyrosine;
      case 'A':
      case 'G':
        return STOP;
      }
      break;
    case 'G':
      switch (in[2]) {
      case 'C':
      case 'U':
        return Cysteine;
      case 'G':
        return Tryptophan;
      case 'A':
        return STOP;
      }
    }
    break;
  }
  return NONVALID;
}

proteins_t proteins(const char *const rna) {
  proteins_t data = {.valid = true, .count = 0};
  size_t ii = 0;
  for (; ii < strlen(rna); ii += 3) {
    char tmp[3] = "";
    strncpy(tmp, rna + ii, 3);
    protein_t valid = find(tmp);
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