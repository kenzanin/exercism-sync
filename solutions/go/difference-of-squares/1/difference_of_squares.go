package diffsquares

import "math"

func SquareOfSum(n int) int {
	result := 0
	for i := 1; i <= n; i++ {
		result += i
	}
	return int(math.Pow(float64(result), 2))
}

func SumOfSquares(n int) int {
	result := 0
	for i := 1; i <= n; i++ {
		result += int(math.Pow((float64(i)), 2))
	}
	return result
}

func Difference(n int) int {
	return SquareOfSum(n) - SumOfSquares(n)
}
