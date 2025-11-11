#include "robot_name.h"
#include <cstdio>
#include <random>
#include <string>

namespace robot_name {
std::random_device rd;
std::mt19937 ran(rd());
robot::robot() { reset(); }
std::string robot::name() const { return var_name.c_str(); }
void robot::reset() {
  var_name.clear();
  std::uniform_int_distribution<int> random_num(0, 999);
  std::uniform_int_distribution<int> random_char('A', 'Z');
  var_name.push_back(random_char(ran));
  var_name.push_back(random_char(ran));
  char tmp[5]{};
  sprintf(tmp, "%03d", random_num(ran));
  var_name += std::string(tmp);
}
} // namespace robot_name