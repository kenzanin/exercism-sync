#include "linked_list.h"
#include <limits.h>
#include <stdlib.h>

struct list_node {
  struct list_node *prev, *next;
  ll_data_t data;
};

struct list {
  struct list_node *first, *last;
  int count;
};

// constructs a new (empty) list
struct list *list_create(void) {
  struct list *result = (struct list *)calloc(1, sizeof(struct list));
  result->first = NULL;
  result->last = NULL;
  result->count = 0;
  return result;
}

// counts the items on a list
size_t list_count(const struct list *list) { return list->count; }

// inserts item at back of a list
void list_push(struct list *list, ll_data_t item_data) {
  if (list->count == 0) {
    list->last = (struct list_node *)calloc(1, sizeof(struct list_node));
    list->first = list->last;
  } else {
    struct list_node *new_ =
        (struct list_node *)calloc(1, sizeof(struct list_node));
    new_->prev = list->last;
    list->last->next = new_;
    list->last = list->last->next;
  }
  list->last->data = item_data;
  list->count++;
}

// removes item from back of a list
ll_data_t list_pop(struct list *list) {
  ll_data_t result = 0;
  result = list->last->data;
  if (list->count > 1) {
    list->last = list->last->prev;
    free(list->last->next);
  } else if (list->count == 1) {
    free(list->last);
  }
  list->count--;
  return result;
}

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data) {
  if (list->first == NULL) {
    list->first = (struct list_node *)calloc(1, sizeof(struct list_node));
    list->last = list->first;
  } else {
    list->first->prev = (struct list_node *)calloc(1, sizeof(struct list_node));
    list->first->prev->next = list->first;
    list->first = list->first->prev;
  }
  list->first->data = item_data;
  list->count++;
}

// removes item from front of a list
ll_data_t list_shift(struct list *list) {
  ll_data_t result = list->first->data;
  if (list->count > 1) {
    list->first = list->first->next;
    free(list->first->prev);
  } else if (list->count == 1) {
    free(list->last);
  }
  list->count--;
  return result;
}

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data) {
  if (list->first->data == data) {
    if (list->count > 1) {
      list->first = list->first->next;
      free(list->first->prev);
      list->first->prev = NULL;
      list->count--;
    } else {
      free(list->first);
      list->count--;
    }
    return;
  } else if (list->last->data == data) {
    if (list->count > 1) {
      list->last = list->last->prev;
      free(list->last->next);
      list->last->next = NULL;
      list->count--;
    } else {
      free(list->last);
      list->count--;
    }
    return;
  }

  struct list_node *last = list->last;
  while (list->last->prev != NULL) {
    if (list->last->data == data) {
      struct list_node *del = list->last;
      list->last = list->last->prev;
      list->last->next = del->next;
      del->next->prev = list->last;
      free(del);
      list->count--;
      break;
    }
    list->last = list->last->prev;
  }
  list->last = last;
}

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list) {
  int count = list->count;
  for (int i = 0; i < count; i++) {
    list_pop(list);
  }
  free(list);
}
