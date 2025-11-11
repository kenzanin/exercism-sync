package account

import "sync"

// Define the Account type here.
const (
	open  = true
	close = false
)

type Account struct {
	status  bool
	balance int64
	w       sync.Mutex
}

func Open(amount int64) *Account {
	if amount < 0 {
		return nil
	}
	return &Account{status: open, balance: amount}
}

func (a *Account) Balance() (int64, bool) {
	if !a.status {
		return 0, false
	}
	return a.balance, open
}

func (a *Account) Deposit(amount int64) (int64, bool) {
	a.w.Lock()
	if !a.status {
		a.w.Unlock()
		return 0, false
	}

	if a.balance+amount <= 0 {
		a.w.Unlock()
		return 0, false
	}

	a.balance += amount
	a.w.Unlock()
	return a.balance, open
}

func (a *Account) Close() (int64, bool) {
	if a.status {
		a.status = close
		return a.balance, true
	} else {
		return 0, false
	}
}
