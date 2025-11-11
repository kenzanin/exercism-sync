package summultiples

func SumMultiples(limit int, divisors ...int) int {
	list := map[int]int{}
	for _, i := range divisors {
		if limit < i || i == 0 {
			break
		}
		for ii := 1; ii < limit; ii++ {
			if ii%i == 0 {
				list[ii]++
			}
		}
	}
	sum := 0
	for i := range list {
		sum += i
	}

	return sum
}
