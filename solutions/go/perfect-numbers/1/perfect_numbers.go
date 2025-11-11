package perfect

import (
	"fmt"
)

// Define the Classification type here.
type Classification int

const (
	ClassificationAbundant Classification = iota
	ClassificationDeficient
	ClassificationPerfect
)

var ErrOnlyPositive = fmt.Errorf("")

func Classify(n int64) (Classification, error) {
	if n <= 0 {
		return 0, ErrOnlyPositive
	}

	sum := int64(0)
	for i := int64(1); i <= int64(n/2); i++ {
		if n%i == 0 {
			sum += i
		}
	}
	if sum == n {
		return ClassificationPerfect, nil
	}
	if sum < n {
		return ClassificationDeficient, nil
	}

	return ClassificationAbundant, nil
}
