#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

size_t List::size() { return element.size(); }

void List::push(int entry) { element.push_back(entry); }

int List::pop() {
  auto data = element.back();
  element.pop_back();
  return data;
}

void List::reverse() { element.reverse(); }

List::~List() { element.clear(); }

} // namespace simple_linked_list
