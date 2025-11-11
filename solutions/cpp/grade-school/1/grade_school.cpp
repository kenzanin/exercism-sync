#include "grade_school.h"
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

namespace grade_school {
void school::add(std::string nama, int kelas) {
  std::vector<std::string> tmp = murid[kelas];
  tmp.push_back(nama);
  std::sort(tmp.begin(), tmp.end());
  murid[kelas] = tmp;
}

std::map<int, std::vector<std::string>> school::roster() const { return murid; }

std::vector<std::string> school::grade(int kelas) const {

  std::vector<std::string> tmp{};
  if (murid.count(kelas) <= 0)
    return tmp;
  tmp = murid.at(kelas);
  return tmp;
}
} // namespace grade_school
