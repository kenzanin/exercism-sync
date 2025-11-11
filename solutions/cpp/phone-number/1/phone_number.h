#include <string>
#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H

#include <cctype>
#include <stdexcept>
#include <string>
#include <algorithm>

namespace phone_number {
class phone_number {
  std::string num{};

public:
  explicit phone_number(const std::string &input);
  const std::string number() const;
  const std::string area_code() const;
  operator std::string() const;
};

} // namespace phone_number

#endif // PHONE_NUMBER_H