#include "binary_search.h"
#include "math.h"

int bSearch(int value, const int *arr, size_t start, size_t end);
int bSearch(int value, const int *arr, size_t start, size_t end) {
  if (end >= start) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == value)
      return mid;
    if (arr[mid] > value)
      return bSearch(value, arr, start, mid - 1);
    return bSearch(value, arr, start + 1, end);
  }
  return -1;
}

const int *binary_search(int value, const int *arr, size_t length) {
  if (length == 0)
    return NULL;
  int index = bSearch(value, arr, 0, length);
  return (index == -1 ? NULL : &arr[index]);
}
