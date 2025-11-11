#include "gigasecond.h"

time_t gigasecond_after(time_t time) {
  time += 1e9;
  return time;
}
