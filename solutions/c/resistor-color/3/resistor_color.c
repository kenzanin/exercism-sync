#include "resistor_color.h"

const resistor_band_t *colors() {
  static const resistor_band_t result[] = {BLACK, BROWN, RED,    ORANGE, YELLOW,
                                           GREEN, BLUE,  VIOLET, GREY,   WHITE};
  return result;
}

int color_code(resistor_band_t input) { return input; }
