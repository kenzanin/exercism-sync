#include "phone_number.h"
#include <algorithm>
#include <cctype>
#include <pstl/glue_algorithm_defs.h>
#include <stdexcept>
#include <string>

namespace phone_number {
phone_number::phone_number(const std::string &input) : num(input) {
  num.erase(std::remove_if(num.begin(), num.end(),
                           [](const char &c) {
                             if (std::isdigit(c)) {
                               return false;
                             } else {
                               return true;
                             }
                           }),
            num.end());
  if (num.length() <= 9 || num.length() > 11) {
    throw std::domain_error("");
  }
  if (num.length() == 11) {
    if (num.at(0) == '1') {
      num.erase(0, 1);
    } else {
      throw std::domain_error("");
    }
  }
  if (num.at(0) == '0' || num.at(0) == '1' || num.at(3) == '0' ||
      num.at(3) == '1')
    throw std::domain_error("");
}

const std::string phone_number::number() const { return num; }

const std::string phone_number::area_code() const {
  const std::string result = num.substr(0, 3);
  return result;
}

phone_number::operator std::string() const {
  std::string result =
      "(" + area_code() + ") " + num.substr(3, 3) + "-" + num.substr(6);
  return result;
}

} // namespace phone_number
