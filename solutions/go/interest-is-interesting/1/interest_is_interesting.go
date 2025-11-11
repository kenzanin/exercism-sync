package interest

// InterestRate returns the interest rate for the provided balance.
func InterestRate(balance float64) float32 {
	if balance < 0 {
		return 3.213
	} else if balance >= 0 && balance < 1000 {
		return 0.5
	} else if balance >= 1000 && balance < 5000 {
		return 1.621
	} else if balance >= 5000 {
		return 2.475
	}
	return 0.0
}

// Interest calculates the interest for the provided balance.
func Interest(balance float64) float64 {
	return float64(InterestRate(balance)) * 0.01 * balance
}

// AnnualBalanceUpdate calculates the annual balance update, taking into account the interest rate.
func AnnualBalanceUpdate(balance float64) float64 {
	return Interest(balance) + balance
}

// YearsBeforeDesiredBalance calculates the minimum number of years required to reach the desired balance.
func YearsBeforeDesiredBalance(balance, targetBalance float64) int {
	count := 0
	for count = 0; balance < targetBalance; count++ {
		balance = AnnualBalanceUpdate(balance)
	}
	return count
}
