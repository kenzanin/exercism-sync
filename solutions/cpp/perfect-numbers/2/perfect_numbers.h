#if !defined(PERFECT_NUMBERS_H)
#define PERFECT_NUMBERS_H
#include <inttypes.h>

namespace perfect_numbers {
enum enum_classify {
  perfect,
  abundant,
  deficient,
};

enum_classify classify(int32_t);

}  // namespace perfect_numbers

#endif  // PERFECT_NUMBERS_H