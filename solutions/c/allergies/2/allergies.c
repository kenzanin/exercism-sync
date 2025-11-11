#include "allergies.h"
#include <stdbool.h>

bool is_allergic_to(allergen_t alergen, int num) {
  for (int i = 0; i < ALLERGEN_COUNT; i++) {
    if ((int)alergen == i && (num & (1 << i)) != 0) {
      return true;
    }
  }
  return false;
}

allergen_list_t get_allergens(int num) {
  allergen_list_t result = {0};
  int tmp = num;
  for (int i = 0; i < ALLERGEN_COUNT; i++) {
    if (is_allergic_to(i, tmp)) {
      result.allergens[i] = true;
      result.count++;
    }
  }
  return result;
}
