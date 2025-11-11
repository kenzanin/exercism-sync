#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef int buffer_value_t;

typedef struct {
  int head;
  int tail;
  int capacity;
  int *data;
  int count;
  // bool is_full;
  // bool is_empty;
} circular_buffer_t;

int write(circular_buffer_t *cbuf, buffer_value_t val);
int overwrite(circular_buffer_t *cbuf, buffer_value_t val);
int read(circular_buffer_t *cbuf, buffer_value_t *val);
circular_buffer_t *new_circular_buffer(int capacity);
void delete_buffer(circular_buffer_t *cbuf);
void clear_buffer(circular_buffer_t *cbuf);

#endif
