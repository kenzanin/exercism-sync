#include "raindrops.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *convert(char result[], int drops) {

  if ((drops % 5 == 0) && (drops % 7 == 0) && (drops%3==0))
    strcpy(result, "PlingPlangPlong");
  else if ((drops % 3 == 0) && (drops % 5 == 0))
    strcpy(result, "PlingPlang");
  else if ((drops % 3 == 0) && (drops % 7 == 0))
    strcpy(result, "PlingPlong");
  else if ((drops % 5 == 0) && (drops % 7 == 0))
    strcpy(result, "PlangPlong");
  else if (drops % 3 == 0)
    strcpy(result, "Pling");
  else if (drops % 5 == 0)
    strcpy(result, "Plang");
  else if (drops % 7 == 0)
    strcpy(result, "Plong");
  else
    sprintf(result, "%d", drops);
  return 0;
}