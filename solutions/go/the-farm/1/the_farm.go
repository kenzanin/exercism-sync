package thefarm

import (
	"errors"
	"fmt"
)

// See types.go for the types defined for this exercise.

// TODO: Define the SillyNephewError type here.
type SillyNephewError struct {
	cows int
}

func (s *SillyNephewError) Error() string {
	return fmt.Sprintf("silly nephew, there cannot be %d cows", s.cows)
}

// DivideFood computes the fodder amount per cow for the given cows.
func DivideFood(weightFodder WeightFodder, cows int) (float64, error) {
	a, e := weightFodder.FodderAmount()
	if a < 0 {
		if e == nil || e == ErrScaleMalfunction {
			return 0, errors.New("negative fodder")
		} else {
			return 0, e
		}
	}

	if e != nil {
		if a > 0 && e == ErrScaleMalfunction {
			a *= 2
		} else {
			return 0, e
		}
	}

	if cows < 0 {
		return 0, &SillyNephewError{cows}
	}

	if cows == 0 {
		return 0, errors.New("division by zero")
	}
	return (a / float64(cows)), nil
}
