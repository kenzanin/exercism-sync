#include "rna_transcription.h"
#include <string>
/*
G -> C
C -> G
T -> A
A -> U
*/

namespace rna_transcription {
std::string to_rna(std::string test) {
  for (auto &c : test) {
    c = to_rna(c);
  }

  return test;
}

char to_rna(char c) {
  switch (c) {
  case 'G':
    c = 'C';
    break;
  case 'C':
    c = 'G';
    break;
  case 'T':
    c = 'A';
    break;
  case 'A':
    c = 'U';
    break;
  }
  return c;
}
} // namespace rna_transcription
