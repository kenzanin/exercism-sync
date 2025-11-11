#include "robot_simulator.h"
#include <utility>

namespace robot_simulator {
std::pair<int, int> Robot::get_position() const { return {x, y}; }
Bearing Robot::get_bearing() const { return dir; }
Robot::Robot(std::pair<int, int> i_pos, Bearing i_dir) {
  x = i_pos.first;
  y = i_pos.second;
  dir = i_dir;
}
void Robot::turn_left() {
  int i = static_cast<int>(dir);
  i = i <= 0 ? 3 : i - 1;
  dir = static_cast<Bearing>(i);
}
void Robot::turn_right() {
  int i = static_cast<int>(dir);
  i = i >= 3 ? 0 : i + 1;
  dir = static_cast<Bearing>(i);
}
void Robot::advance() {
  switch (dir) {
  case Bearing::NORTH:
    y++;
    break;
  case Bearing::EAST:
    x++;
    break;
  case Bearing::SOUTH:
    y--;
    break;
  case Bearing::WEST:;
    x--;
    break;
  }
}

void Robot::execute_sequence(const std::string &str) {
  for (const auto &c : str) {
    switch (c) {
    case 'R':
      turn_right();
      break;
    case 'L':
      turn_left();
      break;
    case 'A':
      advance();
      break;
    }
  }
}

} // namespace robot_simulator
