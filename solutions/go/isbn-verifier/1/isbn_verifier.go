package isbn

import (
	"strings"
)

func IsValidISBN(isbn string) bool {
	isbn = strings.ReplaceAll(isbn, "-", "")
	if len(isbn) == 0 || len(isbn) != 10 {
		return false
	}
	tmp := strings.IndexRune(isbn, 'X')
	if tmp < 9 && tmp > 0 {
		return false
	}
	isbn = strings.Replace(isbn, "X", string('9'+1), 1)
	result := 0
	for i, v := range isbn {
		result += int(v-'0') * (10 - i)
	}
	return result%11 == 0
}
