package armstrong

import "math"

func IsNumber(n int) bool {

	list := []int{}
	for i := n; i > 0; i = int(i / 10) {
		list = append(list, i%10)
	}

	result := 0
	for _, ii := range list {
		result += int(math.Pow(float64(ii), float64(len(list))))
	}

	return result == n
}
