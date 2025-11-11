#if !defined(SIMPLE_LINKED_LIST_H)
#define SIMPLE_LINKED_LIST_H

#include <cstddef>
#include <list>

namespace simple_linked_list {

class List {
public:
  List() = default;
  ~List();

  size_t size();
  void push(int enty);
  int pop();
  void reverse();

private:
  std::list<int> element{};
};
} // namespace simple_linked_list

#endif
