#include <algorithm>
#include <string>
#include <vector>

#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H

namespace robot_name {
class robot {
private:
  std::string var_name{};
public:
  robot();
  std::string name() const;
  void reset();
};
} // namespace robot_name

#endif // ROBOT_NAME_H