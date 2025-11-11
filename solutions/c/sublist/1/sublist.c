#include "sublist.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include <limits.h>

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count) {
  if (!base_list && !list_to_compare)
    return EQUAL;
  if (base_list && !list_to_compare)
    return SUBLIST;
  if (!base_list && list_to_compare)
    return SUPERLIST;
  if (base_list_element_count == list_to_compare_element_count) {
    return memcmp(base_list, list_to_compare,
                  base_list_element_count * sizeof(int));
  } else {
    size_t first_count = 0;
    int *first_data = NULL;
    size_t second_count = 0;
    int *second_data = NULL;
    comparison_result_t result;
    if (base_list_element_count > list_to_compare_element_count) {
      first_count = base_list_element_count;
      first_data = base_list;
      second_count = list_to_compare_element_count;
      second_data = list_to_compare;
      result = SUBLIST;
    } else {
      first_count = list_to_compare_element_count;
      first_data = list_to_compare;
      second_count = base_list_element_count;
      second_data = base_list;
      result = SUPERLIST;
    }
    for (size_t i = 0; i <= (first_count - second_count); i++) {
      if (memcmp(first_data + i, second_data, second_count * sizeof(int)) ==
          0) {
        return result;
      }
    }
  }
  return UNEQUAL;
}
