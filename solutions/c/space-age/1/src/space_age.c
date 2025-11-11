#include "space_age.h"

float age(planet_t planet, int64_t seconds) {

  const float EARTH_SECOND = 31557600.0;
  switch (planet) {
  case EARTH:
    return (seconds / EARTH_SECOND);
  case MERCURY:
    return (seconds / (EARTH_SECOND * 0.2408467));
  case VENUS:
    return (seconds / (EARTH_SECOND * 0.61519726));
  case MARS:
    return (seconds / (EARTH_SECOND * 1.8808158));
  case JUPITER:
    return (seconds / (EARTH_SECOND * 11.862615));
  case SATURN:
    return (seconds / (EARTH_SECOND * 29.447498));
  case URANUS:
    return (seconds / (EARTH_SECOND * 84.016846));
  case NEPTUNE:
    return (seconds / (EARTH_SECOND * 164.79132));
  default:
    return 0.0;
  }
  return 0.0;
}