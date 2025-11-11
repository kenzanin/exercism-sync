package account

import "sync"

// Define the Account type here.
const (
	open  = true
	close = false
)

type Account struct {
	m       sync.RWMutex
	status  bool
	balance int64
}

func Open(amount int64) *Account {
	if amount < 0 {
		return nil
	}
	return &Account{status: open, balance: amount}
}

func (a *Account) Balance() (int64, bool) {
	a.m.Lock()
	defer a.m.Unlock()
	if !a.status {
		return 0, false
	}
	return a.balance, open
}

func (a *Account) Deposit(amount int64) (int64, bool) {
	a.m.Lock()
	defer a.m.Unlock()

	if !a.status || a.balance+amount < 0 {
		return 0, false
	}

	a.balance += amount
	return a.balance, open
}

func (a *Account) Close() (int64, bool) {
	a.m.Lock()
	defer a.m.Unlock()

	if a.status {
		a.status = close
		return a.balance, true
	} else {
		return 0, false
	}
}
