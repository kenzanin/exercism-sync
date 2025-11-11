#include "space_age.h"
#include <bits/stdint-uintn.h>

namespace space_age {
space_age::space_age(long _age) { age = _age; }

double space_age::seconds() const { return age; }

double space_age::on_earth() const { return age / 31557600.0; }

double space_age::on_mercury() const { return age / (0.2408467 * 31557600.0); }
double space_age::on_venus() const { return age / (0.61519726 * 31557600.0); }
double space_age::on_mars() const { return age / (1.8808158 * 31557600.0); }
double space_age::on_jupiter() const { return age / (11.862615 * 31557600.0); }
double space_age::on_saturn() const { return age / (29.447498 * 31557600.0); }
double space_age::on_uranus() const { return age / (84.016846 * 31557600.0); }
double space_age::on_neptune() const { return age / (164.79132 * 31557600.0); }

} // namespace space_age
