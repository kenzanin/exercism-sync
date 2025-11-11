#pragma once

#include <string>
#include <vector>
namespace lasagna_master {

struct amount {
  int noodles;
  double sauce;
};

int preparationTime(std::vector<std::string> &, int times = 2);
const amount quantities(std::vector<std::string> &);
void addSecretIngredient(std::vector<std::string> &,
                         const std::vector<std::string> &);
void addSecretIngredient(std::vector<std::string> &, const std::string &);
const std::vector<double> scaleRecipe(const std::vector<double> &, int);
} // namespace lasagna_master
