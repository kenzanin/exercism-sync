#ifndef PYTHAGOREAN_TRIPLET_H
#define PYTHAGOREAN_TRIPLET_H

#include <stdint.h>

struct _triplet_t {
  uint32_t a, b, c;
};
typedef struct _triplet_t triplet_t;

struct _triplets_t {
  triplet_t *triplets;
  uint32_t count;
};
typedef struct _triplets_t triplets_t;

triplets_t *triplets_with_sum(uint32_t sum);
void free_triplets(triplets_t *in);
#endif
