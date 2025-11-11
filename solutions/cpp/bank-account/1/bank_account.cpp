#include "bank_account.h"
#include <stdexcept>

namespace Bankaccount {
void Bankaccount::open() {
  if (saving != nullptr)
    throw std::runtime_error("");
  saving = new int(0);
}
Bankaccount::Bankaccount() {}
Bankaccount::~Bankaccount() { close(); }
int Bankaccount::balance() {
  if (saving == nullptr) {
    throw std::runtime_error("");
  }
  return *saving;
}
void Bankaccount::deposit(int d) {
  if (saving == nullptr || d <= 0)
    throw std::runtime_error("");
  lock.lock();
  *saving += d;
  lock.unlock();
}
void Bankaccount::withdraw(int w) {
  if (saving == nullptr || w <= 0 || *saving < w)
    throw std::runtime_error("");
  lock.lock();
  *saving -= w;
  lock.unlock();
}
void Bankaccount::close() {
  if (saving == nullptr)
    throw std::runtime_error("");
  delete saving;
  saving = nullptr;
}

} // namespace Bankaccount