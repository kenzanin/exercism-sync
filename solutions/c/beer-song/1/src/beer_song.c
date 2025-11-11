#include "beer_song.h"
#include "stdlib.h"
#include "string.h"
#include <stdio.h>

//"99 bottles of beer on the wall, 99 bottles of beer.\n"
//"Take one down and pass it around, 98 bottles of beer on the wall.\n";

void recite(unsigned int start_bottles, unsigned int take_down, char *buffer) {
  char var01[300] = {0};
  char var02[512] = {0};

  int var03 = start_bottles;
  int i = 0;
  for (i = 0; i < (int)take_down; i++) {
    if (i > 0)
      strcat(var02, "\n");
    if (var03 > 1)
      sprintf(var01, "%d bottles of beer on the wall, ", var03);
    else if (var03 == 1)
      sprintf(var01, "%d bottle of beer on the wall, ", var03);
    else if (var03 == 0)
      sprintf(var01, "No more bottles of beer on the wall, ");
    strcat(var02, var01);
    memset((void *)var01, 0, sizeof(var01));

    if (var03 > 1)
      sprintf(var01, "%d bottles of beer.\n", var03);
    if (var03 == 1)
      sprintf(var01, "%d bottle of beer.\n", var03);
    if (var03 == 0)
      sprintf(var01, "no more bottles of beer.\n");
    strcat(var02, var01);
    memset((void *)var01, 0, sizeof(var01));

    if (var03 > 1)
      sprintf(var01, "Take one down and pass it around, ");
    else if (var03 == 1)
      sprintf(var01, "Take it down and pass it around, ");
    else if (var03 == 0)
      sprintf(var01, "Go to the store and buy some more, ");
    strcat(var02, var01);
    memset((void *)var01, 0, sizeof(var01));

    var03--;
    if (var03 == 1)
      sprintf(var01, "%d bottle of beer on the wall.\n", var03);
    else if (var03 > 1)
      sprintf(var01, "%d bottles of beer on the wall.\n", var03);
    else if (var03 == 0)
      sprintf(var01, "no more bottles of beer on the wall.\n");
    else if (var03 < 0)
      sprintf(var01, "%d bottles of beer on the wall.\n", 99);

    strcat(var02, var01);
    memset((void *)var01, 0, sizeof(var01));
  }
  strcpy(buffer, var02);
}
