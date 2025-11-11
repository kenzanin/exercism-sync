#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H
#include <mutex>

namespace Bankaccount {
class Bankaccount {
private:
  int *saving = nullptr;
  std::mutex lock;

public:
  Bankaccount();
  ~Bankaccount();
  void open();
  int balance();
  void deposit(int);
  void withdraw(int);
  void close();
}; // class Bankaccount

} // namespace Bankaccount

#endif // BANK_ACCOUNT_H