#include "protein_translation.h"
#include <cstddef>

namespace protein_translation {
std::vector<std::string> proteins(std::string);
} // namespace protein_translation

std::vector<std::string> protein_translation::proteins(std::string test) {
  std::vector<std::string> var01{};

  for (size_t i = 0; i < test.size();) {
    std::string tmp{};
    tmp = test[i];
    tmp += test[i + 1];
    tmp += test[i + 2];

    std::string result{};
    if (tmp == "AUG")
      result = "Methionine";
    if (tmp == "UUU")
      result = "Phenylalanine";
    if (tmp == "UUC")
      result = "Phenylalanine";
    if (tmp == "UUA" || tmp == "UUG")
      result = "Leucine";
    if (tmp == "UCU" || tmp == "UCC" || tmp == "UCA" || tmp == "UCG")
      result = "Serine";
    if (tmp == "UAU" || tmp == "UAC")
      result = "Tyrosine";
    if (tmp == "UGU" || tmp == "UGC")
      result = "Cysteine";
    if (tmp == "UGG")
      result = "Tryptophan";
    if (tmp == "UAA" || tmp == "UAG" || tmp=="UGA") {
      i = size_t(test.c_str());
      continue;
    }
    var01.push_back(result);
    i += 3;
  }

  return var01;
}
