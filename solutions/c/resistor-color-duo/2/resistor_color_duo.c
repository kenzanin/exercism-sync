#include "resistor_color_duo.h"
#include "math.h"

int color_code(const resistor_band_t *input) {
  int first = input[0];
  int second = input[1];
int result = first * 10 + second;
  return result;
}

const resistor_band_t *colors() { return (resistor_band_t *)0; }
