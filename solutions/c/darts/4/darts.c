#include "darts.h"
#include "math.h"
#include "stdlib.h"

int score(coordinate_t pos) {
  const double mpos = (fabs(pos.x) + fabs(pos.y)) / 2.0;

  const double miss = 7.0F;
  const double middle_circle = 3.5F;
  const double inner_circle = 0.7F;

  if (mpos > miss) {
    return 0;
  }
  if (mpos <= miss && mpos > middle_circle) {
    return 1;
  }

  if (mpos <= middle_circle && mpos > inner_circle) {
    return 5;
  }

  if (mpos <= inner_circle) {
    return 10;
  }

  return 0;
}
