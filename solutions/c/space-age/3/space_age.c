#include "space_age.h"

float age(planet_t planet, int64_t seconds) {
  const float scale[] = {
      [MERCURY] = (0.2408467 / 1.0) * 31557600,
      [VENUS] = (0.61519726 / 1.0) * 31557600,
      [EARTH] = (1.0 / 1.0) * 31557600,
      [MARS] = (1.8808158 / 1.0) * 31557600,
      [JUPITER] = (11.862615 / 1.0) * 31557600,
      [SATURN] = (29.447498 / 1.0) * 31557600,
      [URANUS] = (84.016846 / 1.0) * 31557600,
      [NEPTUNE] = (164.79132 / 1.0) * 31557600,
  };
  return (float)seconds / scale[planet];
}
