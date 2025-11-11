#include "triangle.h"

bool valid(triangle_t t);

bool valid(triangle_t t) {
  if ((t.a > 0 && t.b > 0 && t.c > 0) &&
      (t.a < t.b + t.c && t.b < t.a + t.c && t.c < t.a + t.b))
    return 0;
  return 1;
}

bool is_equilateral(triangle_t t) {
  if (valid(t))
    return 0;
  return (t.a == t.b && t.a == t.c);
}
bool is_isosceles(triangle_t t) {
  if (valid(t))
    return 0;
  return (t.a == t.b || t.a == t.c || t.b == t.c);
}
bool is_scalene(triangle_t t) {
  if (valid(t))
    return 0;
  return (t.a != t.b && t.b != t.c && t.c != t.a);
}
