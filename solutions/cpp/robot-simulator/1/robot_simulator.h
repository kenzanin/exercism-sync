#include <utility>
#if !defined(ROBOT_SIMULATOR_H)
#define ROBOT_SIMULATOR_H

#include <string>

namespace robot_simulator {
enum class Bearing {
  // north, east, south, or west
  NORTH = 0,
  EAST,
  SOUTH,
  WEST
};

class Robot {
private:
  int x{};
  int y{};
  Bearing dir = Bearing::NORTH;

public:
  explicit Robot(std::pair<int, int> i_pos = {0, 0},
                 Bearing i_dir = Bearing::NORTH);
  std::pair<int, int> get_position() const;
  Bearing get_bearing() const;
  void turn_right();
  void turn_left();
  void advance();
  void execute_sequence(const std::string &str);
};
} // namespace robot_simulator

#endif // ROBOT_SIMULATOR_H