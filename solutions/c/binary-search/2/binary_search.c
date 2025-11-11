#include "binary_search.h"
#include "math.h"

const int *bSearch(int value, const int *arr, int start, int end);
const int *bSearch(int value, const int *arr, int start, int end) {
  if (end >= start) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == value)
      return &arr[mid];
    if (arr[mid] > value)
      return bSearch(value, arr, start, mid - 1);
    return bSearch(value, arr, start + 1, end);
  }
  return NULL;
}

const int *binary_search(int value, const int *arr, size_t length) {
  return length == 0 ? NULL : bSearch(value, arr, 0, length);
}
