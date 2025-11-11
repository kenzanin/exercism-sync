#include "lasagna_master.h"
#include <iterator>
#include <vector>

namespace lasagna_master {

int preparationTime(const std::vector<std::string> &layers, int times) {
  return layers.size() * times;
}

const amount quantities(const std::vector<std::string> &layers) {
  auto ret = amount{};
  for (auto const &e : layers) {
    if (e == "noodles") {
      ret.noodles += 50;
    } else if (e == "sauce") {
      ret.sauce += 0.2;
    }
  }
  return ret;
}

void addSecretIngredient(std::vector<std::string> &himel,
                         const std::vector<std::string> &frieren) {
  himel.back() = frieren.back();
}

const std::vector<double> scaleRecipe(const std::vector<double> &portion,
                                      int scale) {
  std::vector<double> ret(portion.size(), 0.0);
  auto ii = ret.begin();
  for (auto i = portion.begin(); i != portion.end(); i++) {
    *ii = *i * (scale / 2.0);
    ii = std::next(ii);
  }
  return ret;
}

void addSecretIngredient(std::vector<std::string> &himel,
                         const std::string &frieren) {
  himel.back() = frieren;
}

} // namespace lasagna_master
