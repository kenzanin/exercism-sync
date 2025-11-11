#include "say.h"
#include <cstddef>
#include <cstdint>
#include <exception>
#include <stdexcept>
#include <string>

namespace say {
const char *satuan_belasan[] = {"",        "one",       "two",      "three",
                                "four",    "five",      "six",      "seven",
                                "eight",   "nine",      "ten",      "eleven",
                                "twelve",  "thirteen",  "fourteen", "fifteen",
                                "sixteen", "seventeen", "eighteen", "nineteen"};
const char *puluhan[] = {"",      "ten",   "twenty",  "thirty", "forty",
                         "fifty", "sixty", "seventy", "eighty", "ninety"};

void helper(std::string *buf, std::string const satuan, int32_t input) {
  if (input <= 0)
    return;

  int i = input / 100;
  if (i > 0) {
    buf->append(buf->length() ? " " : "");
    buf->append(satuan_belasan[i]);
    buf->append(" hundred");
  }

  i = input % 100;
  if (i < 20 && i > 0) {
    buf->append(buf->length() ? " " : "");
    buf->append(satuan_belasan[i]);
  }

  if (i >= 20) {
    int ii = i / 10;
    i = i % 10;
    buf->append(buf->length() ? " " : "");
    buf->append(puluhan[ii]);
    buf->append(i ? "-" : "");
    buf->append(satuan_belasan[i]);
  }

  buf->append(satuan);
}

std::string in_english(size_t input) {
  std::string buf{};
  if (input == 0) {
    buf.append("zero");
    return buf;
  }

  if (input >= 1e12) {
    throw std::domain_error("");
  }

  int i = (input / 1000000000) % (size_t)1e3;
  helper(&buf, " billion", i);
  i = (input / 1000000) % 1000;
  helper(&buf, " million", i);
  i = (input / 1000) % 1000;
  helper(&buf, " thousand", i);
  i = input % 1000;
  helper(&buf, "", i);

  return buf;
}

} // namespace say
