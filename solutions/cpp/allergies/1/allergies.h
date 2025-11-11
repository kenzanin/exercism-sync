#include <string>
#include <unordered_set>
#if !defined(ALLERGIES_H)
#define ALLERGIES_H

namespace allergies {
class allergy_test {
public:
  int nilai{};
  allergy_test(int);
  bool is_allergic_to(std::string);
  std::unordered_set<std::string> get_allergies();
};
} // namespace allergies

#endif // ALLERGIES_H