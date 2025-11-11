#include "circular_buffer.h"
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

circular_buffer_t *new_circular_buffer(int capacity) {
  circular_buffer_t *buffer =
      (circular_buffer_t *)calloc(1, sizeof(circular_buffer_t));
  buffer->data = (int *)calloc(capacity, sizeof(int));
  buffer->head = 0;
  buffer->tail = 0;
  buffer->count = -1;
  buffer->capacity = capacity;
  return buffer;
}

int read(circular_buffer_t *cbuf, buffer_value_t *val) {
  if (cbuf->count == -1) {
    errno = ENODATA;
    return 1;
  }
  *val = cbuf->data[cbuf->tail];
  cbuf->tail++;
  cbuf->tail %= cbuf->capacity;
  cbuf->count--;
  return 0;
}

int write(circular_buffer_t *cbuf, buffer_value_t val) {
  if (cbuf->count == cbuf->capacity - 1) {
    errno = ENOBUFS;
    return 1;
  }
  cbuf->data[cbuf->head] = val;
  cbuf->head++;
  cbuf->head %= cbuf->capacity;
  cbuf->count++;
  return 0;
}

int overwrite(circular_buffer_t *cbuf, buffer_value_t val) {
  if (cbuf->count == cbuf->capacity - 1) {
    cbuf->head = cbuf->tail;
    cbuf->tail++;
    cbuf->tail %= cbuf->capacity;
    cbuf->data[cbuf->head] = val;
  } else {
    write(cbuf, val);
  }
  return 0;
}

void clear_buffer(circular_buffer_t *cbuf) {
  cbuf->head = 0;
  cbuf->tail = 0;
  cbuf->count = -1;
}

void delete_buffer(circular_buffer_t *cbuf) {
  free(cbuf->data);
  free(cbuf);
}
