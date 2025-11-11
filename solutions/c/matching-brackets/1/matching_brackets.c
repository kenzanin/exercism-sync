#include "matching_brackets.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct stack_;
void init(struct stack_ *dst);
void push_(struct stack_ *dst, char data);
bool is_empty_(struct stack_ *dst);
char pop_(struct stack_ *dst);
void exit_now_(struct stack_ *dst);

struct stack_ {
  int index;
  char *data;
  void (*init)(struct stack_ *);
  void (*push)(struct stack_ *, char);
  bool (*is_empty)(struct stack_ *);
  char (*pop)(struct stack_ *);
  void (*exit_now)(struct stack_ *);
};

void init(struct stack_ *dst) {
  dst->data = (char *)calloc(1, sizeof(char));
  dst->index = 0;
}

void push_(struct stack_ *dst, char data) {
  dst->data = (char *)realloc(dst->data, dst->index + 1);
  dst->data[dst->index] = data;
  dst->index++;
}

char pop_(struct stack_ *dst) {
  dst->index--;
  char result = dst->data[dst->index];
  dst->data[dst->index] = 0;
  dst->data = (char *)realloc(dst->data, dst->index);
  return result;
}

bool is_empty_(struct stack_ *dst) { return dst->index == 0; }
void exit_now_(struct stack_ *dst) { free(dst->data); }

bool is_paired(const char *input) {
  struct stack_ stack = {
      .index = 0,
      .data = 0,
      .init = &init,
      .push = &push_,
      .is_empty = &is_empty_,
      .pop = &pop_,
      .exit_now = &exit_now_,
  };

  stack.init(&stack);

  while (*input) {
    switch (*input) {
    case '{':
    case '[':
    case '(':
      stack.push(&stack, *input);
      break;
    case '}':
      if (stack.is_empty(&stack) || stack.pop(&stack) != '{')
        goto hehe;
      break;
    case ']':
      if (stack.is_empty(&stack) || stack.pop(&stack) != '[')
        goto hehe;
      break;
    case ')':
      if (stack.is_empty(&stack) || stack.pop(&stack) != '(')
        goto hehe;
      break;
    default:
      break;
    }
    input++;
  }
  stack.exit_now(&stack);
  return stack.is_empty(&stack);

hehe:
  stack.exit_now(&stack);
  return false;
}
