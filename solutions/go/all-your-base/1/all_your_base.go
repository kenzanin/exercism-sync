package allyourbase

import (
	"errors"
	"math"
)

func ConvertToBase(inputBase int, inputDigits []int, outputBase int) ([]int, error) {
	if len(inputDigits) == 0 && inputBase >= 2 {
		return []int{0}, errors.New("")
	}
	if inputBase < 2 {
		return []int{0}, errors.New("input base must be >= 2")
	}
	if outputBase < 2 {
		return []int{0}, errors.New("output base must be >= 2")
	}

	base10 := 0

	index := len(inputDigits) - 1
	for i := range inputDigits {
		tmp := inputDigits[index]
		if tmp < 0 || tmp >= inputBase {
			return []int{0}, errors.New("all digits must satisfy 0 <= d < input base")
		}
		base10 += inputDigits[index] * int(math.Pow(float64(inputBase), float64(i)))
		index--
	}

	result := []int{}
	if base10 == 0 {
		return []int{0}, nil
	}
	for i := base10; i > 0 || i == outputBase; i /= outputBase {
		result = append([]int{(i % outputBase)}, result...)
	}
	return result, nil
}
