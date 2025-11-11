#include "resistor_color_trio.h"
#include <math.h>

resistor_value_t color_code(const resistor_band_t *input) {
  resistor_value_t result = {0};

  result.value = (input[0] * (input[1] == BLACK ? 1 : 10)) + input[1];

  switch (input[2]) {
  case BLACK: {
    result.unit = OHMS;
  } break;
  case BROWN: {
    result.unit = OHMS;
    result.value *= 10;
  } break;
  case RED: {
    result.unit = KILOOHMS;
  } break;
  case ORANGE: {
    result.unit = KILOOHMS;
  } break;
  case YELLOW: {
    result.unit = KILOOHMS;
    result.value *= 10;
  }
  default:
    break;
  }
  return result;
}