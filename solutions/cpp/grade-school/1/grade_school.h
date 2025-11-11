#include <string>
#include <vector>
#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H
#include "map"
#include "string"
#include "vector"

namespace grade_school {
class school {
public:
  std::map<int, std::vector<std::string>> murid{};
  void add(std::string, int);
  std::map<int, std::vector<std::string>> roster() const;
  std::vector<std::string> grade(int) const;
};
} // namespace grade_school

#endif // GRADE_SCHOOL_H