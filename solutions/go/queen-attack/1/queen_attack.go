package queenattack

import (
	"errors"
	"math"
)

func CanQueenAttack(whitePosition, blackPosition string) (bool, error) {
	to_xy := func(pos string) (int8, int8) {
		x := int8(pos[0] - 'a')
		y := int8(pos[1] - '1')
		return x, y
	}

	if len(whitePosition) < 2 || len(blackPosition) < 2 || whitePosition == blackPosition {
		return false, errors.New("")
	}

	wx, wy := to_xy(whitePosition)
	bx, by := to_xy(blackPosition)
	/*
			  if (queen_1.column == queen_2.column || queen_1.row == queen_2.row ||
		      (abs(queen_1.column - queen_2.column) == abs(queen_1.row - queen_2.row)))
		    return CAN_ATTACK;
	*/

	if bx > 7 || wx > 7 || by > 7 || wy > 7 || bx < 0 || wx < 0 || wy < 0 || by < 0 {
		return false, errors.New("")
	}

	if wx == bx || wy == by || (math.Abs(float64(wx)-float64(bx)) == math.Abs(float64(wy)-float64(by))) {
		return true, nil
	}

	return false, nil
}
