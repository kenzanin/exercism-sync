#include "clock.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *convertToClock(int minutes);
int convertToMinutes(const char *clock);

const char *convertToClock(int minutes) {
  static char result[15] = {0};

  minutes = minutes % 1440;
  minutes = minutes < 0 ? 1440 + minutes : minutes;

  int jam = minutes / 60;
  int minute = minutes % 60;
  sprintf(result, "%02d:%02d", jam, minute);
  return result;
}

int convertToMinutes(const char *clock) {
  int hour = 0;
  int minute = 0;
  sscanf(clock, "%d:%d", &hour, &minute);
  return hour * 60 + minute;
}

clock_t clock_create(int hour, int minute) {
  int minutes = (hour * 60) + minute;
  clock_t result = {0};
  strcpy(result.text, convertToClock(minutes));
  return result;
}

clock_t clock_add(clock_t clock, int minute_add) {
  int minutes = convertToMinutes(clock.text) + minute_add;
  clock_t result;
  strcpy(result.text, convertToClock(minutes));
  return result;
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
  return clock_add(clock, -minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b) {
  return strcmp(a.text, b.text) == 0;
}
