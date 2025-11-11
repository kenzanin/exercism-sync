#include "say.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void helper(char **buf, const char *satuan, size_t angka);

static const char *satuan_dan_belasan[] = {
    "",        "one",     "two",       "three",    "four",
    "five",    "six",     "seven",     "eight",    "nine",
    "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static const char *puluhan[] = {"",       "ten",   "twenty", "thirty",
                                "forty",  "fifty", "sixty",  "seventy",
                                "eighty", "ninety"};

void helper(char **buf, const char *satuan, size_t input) {
  if (input <= 0) {
    return;
  }
  int i = input / 100;
  if (i > 0)
    sprintf(*buf + strlen(*buf), "%s%s%s", strlen(*buf) ? " " : "",
            satuan_dan_belasan[i], " hundred");
  i = input % 100;
  if (i < 20 && i > 0) {
    sprintf(*buf + strlen(*buf), "%s%s", (strlen(*buf) ? " " : ""),
            satuan_dan_belasan[i]);
  }
  if (i >= 20) {
    int ii = i % 10;
    i = i / 10;
    sprintf(*buf + strlen(*buf), "%s%s%s%s", (strlen(*buf) ? " " : ""),
            puluhan[i], ii ? "-" : "", satuan_dan_belasan[ii]);
  }
  sprintf(*buf + strlen(*buf), "%s", satuan);
}

int say(int64_t input, char **ans) {
  *ans = calloc(1000, sizeof(char));
  if (input == 0) {
    strcpy(*ans, "zero"); // NOLINT
    return 0;
  }
  if (input < 0 || input > (1000000000000 - 1)) {
    return -1;
  }
  size_t i = input / 1000000000;
  helper(&(*ans), " billion", i);
  i = input % 1000000000;
  i = i / 1000000;
  helper(&(*ans), " million", i);
  i = input % 1000000;
  i = i / 1000;
  helper(&(*ans), " thousand", i);
  i = input % 1000;
  helper(&(*ans), "", i);
  return 0;
}
