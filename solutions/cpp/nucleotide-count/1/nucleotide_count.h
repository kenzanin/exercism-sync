#include <cstdint>
#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H
#include "map"
#include "string"

namespace nucleotide_count {
class counter {
public:
  std::map<char, int> tmp{};
  counter(const std::string&);
  const std::map<char, int> nucleotide_counts() const;
  int count(const char &c) const;
};
} // namespace nucleotide_count
#endif // NUCLEOTIDE_COUNT_H