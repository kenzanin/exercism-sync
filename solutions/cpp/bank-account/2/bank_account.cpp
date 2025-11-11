#include "bank_account.h"
#include <exception>
#include <optional>
#include <stdexcept>

namespace Bankaccount {
void Bankaccount::open() {
  if (saving)
    throw std::runtime_error("");
  saving = 0;
}
Bankaccount::Bankaccount() {}

int Bankaccount::balance() {
  if (!saving) {
    throw std::runtime_error("");
  }
  return saving.value();
}

void Bankaccount::deposit(int d) {
  if (!saving || d < 0)
    throw std::runtime_error("");
  calc(d);
}

void Bankaccount::withdraw(int w) {
  if (!saving || saving.value() < w || w < 0)
    throw std::runtime_error("");
  calc(-w);
}
void Bankaccount::close() {
  if (!saving)
    throw std::runtime_error("");
  saving.reset();
}

void Bankaccount::calc(int d) {
  lock.lock();
  saving = saving.value() + d;
  lock.unlock();
}

} // namespace Bankaccount
