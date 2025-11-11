#include "pascals_triangle.h"
#include "stdint.h"
#include "stdlib.h"

int factorial(int n);
int ncr(int n, int r);

void free_triangle(uint8_t **triangle, size_t rows) {
  for (size_t i = 0; i < rows; i++) {
    free(triangle[i]);
  }
}

int factorial(int n) {
  int result = 0;
  for (result = 1; n > 1; n--) {
    result *= n;
  }
  return result;
}

int ncr(int n, int r) {
  return factorial(n) / (factorial(n - r) * factorial(r));
}

uint8_t **create_triangle(size_t rows) {
  size_t rowsx = (rows == 0 ? 1 : rows);
  uint8_t **result = calloc(rowsx, sizeof(uint8_t *));
  for (size_t i = 0; i < rowsx; i++) {
    result[i] = calloc(rowsx, sizeof(uint8_t));
  }
  if (rows == 0)
    return result;

  for (size_t i = 0; i < rows; i++) {
    for (size_t ii = 0; ii <= i; ii++) {
      result[i][ii] = ncr(i, ii);
    }
  }
  return result;
}
