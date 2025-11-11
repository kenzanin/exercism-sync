package darts

import "math"

func Score(x, y float64) int {
	pos := (math.Abs(x) + math.Abs(y)) / 2.0
	if pos > 7 {
		return 0
	} else if pos > 3.5 {
		return 1
	} else if pos <= 3.5 && pos > 0.7 {
		return 5
	} else if pos <= 0.7 {
		return 10
	}
	return 0
}
