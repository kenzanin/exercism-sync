#include "meetup.h"
#include "string.h"
#include "time.h"
#include <stdio.h>
#include <time.h>

int dayOfWeek(int y, int m, int d);

int dayOfWeek(int y, int m, int d) {
  struct tm tm = {.tm_year = y, .tm_mon = m, .tm_mday = d};
  time_t t = mktime(&tm);
  int eval = localtime(&t)->tm_wday;
  return eval;
}

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week) {
  int rev = 0;
  int date = -1;
  if (strcmp(week, "teenth") == 0)
    date = 13;
  else if (strcmp(week, "first") == 0)
    date = 1;
  else if (strcmp(week, "second") == 0)
    date = 8;
  else if (strcmp(week, "third") == 0)
    date = 15;
  else if (strcmp(week, "fourth") == 0)
    date = 22;
  else if (strcmp(week, "last") == 0) {
    switch (month) {
    case 4:
    case 6:
    case 9:
    case 11:
      date = 30;
      rev = 1;
      break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      date = 31;
      rev = 1;
      break;
    case 2:
      if (year % 4 == 0)
        date = 29;
      else
        date = 28;
      rev = 1;
      break;
    }
  }

  int weekday02 = -1;
  if (strcmp(day_of_week, "Monday") == 0)
    weekday02 = 1;
  else if (strcmp(day_of_week, "Tuesday") == 0)
    weekday02 = 2;
  else if (strcmp(day_of_week, "Wednesday") == 0)
    weekday02 = 3;
  else if (strcmp(day_of_week, "Thursday") == 0)
    weekday02 = 4;
  else if (strcmp(day_of_week, "Friday") == 0)
    weekday02 = 5;
  else if (strcmp(day_of_week, "Saturday") == 0)
    weekday02 = 6;
  else if (strcmp(day_of_week, "Sunday") == 0)
    weekday02 = 0;

  int i = 0;
  if (rev == 0) {
    for (i = date; dayOfWeek(year - 1900, month - 1, i) != weekday02; i++) {
    }
  } else {
    for (i = date; dayOfWeek(year - 1900, month - 1, i) != weekday02; i--) {
    }
  }
  return i;
}