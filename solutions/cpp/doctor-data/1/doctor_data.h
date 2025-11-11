#include <string>
#pragma once
namespace star_map {
enum System {
  Sol,
  BetaHydri,
  EpsilonEridani,
  AlphaCentauri,
  DeltaEridani,
  Omicron2Eridani
};
}
namespace heaven {
class Vessel {
public:
  Vessel(const std::string &in1, unsigned int in2,
         star_map::System in3 = star_map::System::Sol);
  Vessel replicate(const std::string &in1);
  void make_buster();
  bool shoot_buster();
  star_map::System current_system;
  unsigned int generation;
  const std::string name;
  int busters = 0;
};
const std::string get_older_bob(const Vessel &in1, const Vessel &in2);
bool in_the_same_system(const Vessel &in1, const Vessel &in2);
} // namespace heaven
