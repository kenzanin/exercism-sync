package pascal

func Triangle(n int) [][]int {
	/*
		for (size_t i = 0; i < rows; i++) {
			for (size_t ii = 0; ii <= i; ii++) {
				result[i][ii] = ncr(i, ii);
			}
		}
	*/

	factorial := func(i int) int {
		result := 1
		for ; i > 1; i-- {
			result *= i
		}
		return result
	}

	ncr := func(n, r int) int {
		return factorial(n) / (factorial(n-r) * factorial(r))
	}

	result := [][]int{}
	for i := 0; i < n; i++ {
		test := make([]int, i+1)
		result = append(result, test)
		for ii := 0; ii <= i; ii++ {
			result[i][ii] = ncr(i, ii)
		}
	}
	return result
}
