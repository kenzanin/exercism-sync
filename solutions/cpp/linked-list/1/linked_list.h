#pragma once
#include <algorithm>
#include <list>
namespace linked_list {
template <typename T> class List {
public:
  List();
  ~List();
  std::list<T> *data;
  void push(T in);
  void unshift(T in);
  T pop();
  T shift();
  int count();
  void erase(T in);

protected:
};
template <typename T> List<T>::List() { data = new std::list<T>(); }
template <typename T> void List<T>::push(T in) { data->push_back(in); }
template <typename T> T List<T>::pop() {
  auto ret = data->back();
  data->pop_back();
  return ret;
}
template <typename T> T List<T>::shift() {
  auto ret = data->front();
  data->pop_front();
  return ret;
}
template <typename T> void List<T>::unshift(T in) { data->push_front(in); };
template <typename T> int List<T>::count() { return data->size(); }
template <typename T> void List<T>::erase(T in) {
  auto it = std::find(data->begin(), data->end(), in);
  if (it != data->end())
    data->erase(it);
}
template <typename T> List<T>::~List() { delete data; }
} // namespace linked_list
