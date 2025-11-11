#include "triangle.h"

bool is_equilateral(triangle_t shape) {
  return (shape.a == shape.b && shape.b == shape.c) &&
         (shape.a > 0 && shape.b > 0 && shape.c > 0);
}
bool is_isosceles(triangle_t shape) {
  return ((shape.a == shape.b) || (shape.a == shape.c) ||
          (shape.b == shape.c)) &&
         ((shape.a + shape.b) >= shape.c) && ((shape.a + shape.c) >= shape.b) &&
         ((shape.b + shape.c) >= shape.a);
}
bool is_scalene(triangle_t shape) {
  return (shape.a != shape.b) && (shape.a != shape.b) && (shape.c != shape.a) &&
         ((shape.a + shape.c) >= shape.b) && ((shape.b + shape.c) >= shape.a);
}
