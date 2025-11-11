#include "doctor_data.h"
namespace heaven {
Vessel::Vessel(const std::string &in1, unsigned int in2, star_map::System in3)
    : current_system(in3), generation(in2), name(in1) {}
Vessel Vessel::replicate(const std::string &in1) {
  return Vessel{in1, generation + 1, current_system};
}
void Vessel::make_buster() { busters++; }
bool Vessel::shoot_buster() {
  busters--;
  return busters >= 0;
}
const std::string get_older_bob(const Vessel &in1, const Vessel &in2) {
  return in1.generation < in2.generation ? in1.name : in2.name;
}
bool in_the_same_system(const Vessel &in1, const Vessel &in2) {
  return in1.current_system == in2.current_system;
}
} // namespace heaven