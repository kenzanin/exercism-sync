package chessboard

import "reflect"

// Declare a type named File which stores if a square is occupied by a piece - this will be a slice of bools
type File struct {
	F1, F2, F3, F4, F5, F6, F7, F8 bool
}

// Declare a type named Chessboard which contains a map of eight Files, accessed with keys from "A" to "H"
type Chessboard map[string]File

// CountInFile returns how many squares are occupied in the chessboard,
// within the given file.
func CountInFile(cb Chessboard, file string) int {
	result := 0
	tmp := reflect.ValueOf(cb[file])
	for i := 0; i < tmp.NumField(); i++ {
		if tmp.Field(i).Interface() == true {
			result++
		}
	}
	return result
}

// CountInRank returns how many squares are occupied in the chessboard,
// within the given rank.
func CountInRank(cb Chessboard, rank int) int {
	if rank > 8 || rank <= 0 {
		return 0
	}
	result := 0
	for _, v := range cb {
		tmp := reflect.ValueOf(v)
		if tmp.Field(rank-1).Interface() == true {
			result++
		}
	}
	return result
}

// CountAll should count how many squares are present in the chessboard.
func CountAll(cb Chessboard) int {
	result := 0
	for _, v := range cb {
		tmp := reflect.TypeOf(v).NumField()
		result += tmp
	}
	return result
}

// CountOccupied returns how many squares are occupied in the chessboard.
func CountOccupied(cb Chessboard) int {
	result := 0
	for i := range cb {
		result += CountInFile(cb, i)
	}
	return result
}
