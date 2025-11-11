#include "pythagorean_triplet.h"
#include <stdlib.h>

triplets_t *triplets_with_sum(uint32_t sum) {
  triplets_t *data = calloc(1, sizeof(triplets_t));
  for (uint64_t a = 1; a < (sum / 3) + 1; a++) {
    for (uint64_t b = a; b < ((sum - a) / 2) + 1; b++) {
      uint64_t c = sum - a - b;
      if ((a * a + b * b) == c * c) {
        data->count++;
        if (data->count == 1) {
          data->triplets = calloc(data->count, sizeof(triplet_t));
        } else {
          void *tmp_ptr = NULL;
          tmp_ptr = realloc(data->triplets, data->count * sizeof(triplet_t));
          data->triplets = tmp_ptr;
        }
        triplet_t tmp = {a, b, c};
        data->triplets[data->count - 1] = tmp;
      }
    }
  }
  return data;
}

void free_triplets(triplets_t *in) {
  free(in->triplets);
  free(in);
}
