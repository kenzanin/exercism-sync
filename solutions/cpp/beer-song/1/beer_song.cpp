#include "beer_song.h"
#include <cstdio>
#include <string>

namespace beer_song {
std::string verse(int test1) {
  std::string str{};

  str.assign(test1 > 0 ? std::to_string(test1) : "No more");
  str.append(test1 > 1 ? " bottles" : test1 == 0 ? " bottles" : " bottle");
  str.append(" of beer on the wall, ");

  if (test1 > 0) {
    str.append(std::to_string(test1));
    str.append(test1 > 1 ? " bottles" : " bottle");
    str.append(" of beer.\n");
    str.append("Take ");
    str.append(test1 > 1 ? "one" : "it");
    str.append(" down and pass it around, ");
    str.append((test1 - 1) > 0 ? std::to_string(test1 - 1) : "no more");
    str.append((test1 - 1) == 1 ? " bottle" : " bottles");
    str.append(" of beer on the wall.\n");
  } else {
    str.append("no more bottles of beer.\nGo to the store and buy some more, "
               "99 bottles of beer on the wall.\n");
  }

  std::string result{};
  result.assign(str);
  return result;
}

std::string sing(int test1, int test2) {
  std::string result{};
  for (int i = test1; i >= test2; i--) {
    result.append(verse(i));
    if (i > test2)
      result.append("\n");
  }
  return result;
}

} // namespace beer_song
