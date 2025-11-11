package luhn

import (
	"strings"
	"unicode"
)

func Valid(id string) bool {
	id = strings.ReplaceAll(id, " ", "")
	if len(id) <= 1 {
		return false
	}
	count := 1
	sum := 0
	for i := len(id) - 1; i >= 0; i-- {
		if unicode.IsPunct(rune(id[i])) || unicode.IsLetter(rune(id[i])) {
			return false
		}

		tmp := int(id[i] - '0')
		if count&1 == 0 {
			tmp *= 2
			if tmp > 9 {
				tmp -= 9
			}
		}
		sum += tmp
		count++
	}
	return sum%10 == 0
}
