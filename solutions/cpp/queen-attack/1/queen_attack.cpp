#include "queen_attack.h"

#include <stdexcept>
#include <utility>

namespace queen_attack {
chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black)
    : black_pos(black), white_pos(white) {
  auto check_if = [](const std::pair<int, int> &p, const int min,
                     const int max) -> bool {
    if ((p.first < min || p.first > max) ||
        (p.second < min || p.second > max)) {
      return true;
    }
    return false;
  };

  if (check_if(white_pos, 0, 7) || check_if(black_pos, 0, 7)) {
    throw std::domain_error("");
  }
}

std::pair<int, int> chess_board::white() const { return white_pos; }
std::pair<int, int> chess_board::black() const { return black_pos; }

//  if (queen_1.column == queen_2.column || queen_1.row == queen_2.row ||
//      (abs(queen_1.column - queen_2.column) == abs(queen_1.row -
//      queen_2.row)))
//    return CAN_ATTACK;
bool chess_board::can_attack() const {
  if (white_pos.first == black_pos.first ||
      white_pos.second == black_pos.second ||
      std::abs(white_pos.first - black_pos.first) ==
          std::abs(white_pos.second - black_pos.second)) {
    return true;
  }
  return false;
}
}  // namespace queen_attack
