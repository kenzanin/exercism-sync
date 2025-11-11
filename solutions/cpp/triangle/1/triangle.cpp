#include "triangle.h"
#include "map"
#include <stdexcept>

namespace triangle {
flavor kind(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0 || a + b < c || a + c < b || b + c < a)
        throw std::domain_error("error");
    std::map<double, double> sisi{};
    sisi[a]++;
    sisi[b]++;
    sisi[c]++;
    if (sisi.at(a) == 3)
        return flavor::equilateral;
    if ((sisi.at(a) == 2 && (sisi.at(b) == 1 || sisi.at(c) == 1))
            || (sisi.at(a)==1 && sisi.at(b)==2))
        return flavor::isosceles;
    return flavor::scalene;
}
} // namespace triangle
