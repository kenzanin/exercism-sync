#include <utility>
#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H

namespace queen_attack {
class chess_board {
  std::pair<int, int> black_pos{}, white_pos{};

 public:
  chess_board(std::pair<int, int>, std::pair<int, int>);
  std::pair<int, int> white() const;
  std::pair<int, int> black() const;
  bool can_attack() const;
};
}  // namespace queen_attack

#endif  // QUEEN_ATTACK_H