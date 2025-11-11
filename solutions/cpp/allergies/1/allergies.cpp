#include "allergies.h"

namespace allergies {
allergy_test::allergy_test(int test) { nilai = test; }
bool allergy_test::is_allergic_to(std::string test) {
  if (test == "eggs" && (nilai & 0x01))
    return true;
  if (test == "peanuts" && (nilai & 0x02))
    return true;
  if (test == "shellfish" && (nilai & 0x04))
    return true;
  if (test == "strawberries" && (nilai & 0x08))
    return true;
  if (test == "tomatoes" && (nilai & 0x10))
    return true;
  if (test == "chocolate" && (nilai & 0x20))
    return true;
  if (test == "pollen" && (nilai & 0x40))
    return true;
  if (test == "cats" && (nilai & 0x80))
    return true;

  return false;
}

std::unordered_set<std::string> allergy_test::get_allergies() {
  std::unordered_set<std::string> result{};
  if (nilai & 0x01)
    result.insert("eggs");
  if (nilai & 0x02)
    result.insert("peanuts");
  if (nilai & 0x04)
    result.insert("shellfish");
  if (nilai & 0x08)
    result.insert("strawberries");
  if (nilai & 0x10)
    result.insert("tomatoes");
  if (nilai & 0x20)
    result.insert("chocolate");
  if (nilai & 0x40)
    result.insert("pollen");
  if (nilai & 0x80)
    result.insert("cats");

  return result;
}

} // namespace allergies
