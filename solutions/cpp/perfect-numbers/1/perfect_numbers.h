#if !defined(PERFECT_NUMBERS_H)
#define PERFECT_NUMBERS_H

namespace perfect_numbers {
enum enum_classify {
  perfect,
  abundant,
  deficient,
};

enum_classify classify(int);

}  // namespace perfect_numbers

#endif  // PERFECT_NUMBERS_H