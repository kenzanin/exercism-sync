#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H
#include <stdexcept>

namespace circular_buffer {
template <typename T> class circular_buffer {
  int head{}, tail{}, size{}, contents{};
  T *buf{};

public:
  explicit circular_buffer(int n);
  T read();
  void write(T);
  void clear();
  void overwrite(T n);
  ~circular_buffer();
};

template <typename T> circular_buffer<T>::~circular_buffer() { delete[] buf; }

template <typename T> T circular_buffer<T>::read() {
  if (contents == 0) {
    throw std::domain_error("");
  }
  auto x = buf[tail++];
  tail %= size;
  contents--;

  return x;
}

template <typename T> circular_buffer<T>::circular_buffer(int n) {
  size = n;
  clear();
}

template <typename T> void circular_buffer<T>::write(T n) {
  if (contents == size) {
    throw std::domain_error("");
  }

  buf[head++] = n;
  head %= size;
  contents++;
}

template <typename T> void circular_buffer<T>::clear() {
  buf = new T[size];
  head = 0;
  tail = 0;
  contents = 0;
}

template <typename T> void circular_buffer<T>::overwrite(T n) {
  if (contents == size) {
    buf[tail++] = n;
    tail %= size;
  } else {
    write(n);
  }
}

} // namespace circular_buffer

#endif // CIRCULAR_BUFFER_H