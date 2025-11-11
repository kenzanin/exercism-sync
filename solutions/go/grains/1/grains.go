package grains

import (
	"errors"
	"math"
)

func Square(number int) (uint64, error) {
	if number <= 0 || number > 64 {
		return 0, errors.New("")
	}
	var result uint64 = 0
	result = uint64(math.Pow(2, float64(number-1)))
	return result, nil
}

func Total() uint64 {
	var result uint64 = 0
	for i := 1; i <= 64; i++ {
		var tmp, _ = Square(i)
		result += tmp
	}
	return result
}
