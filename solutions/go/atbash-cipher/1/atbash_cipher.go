package atbash

import (
	"strings"
	"unicode"
)

func Atbash(s string) string {
	arr := string("zyxwvutsrqponmlkjihgfedcba")
	result := ""
	s = strings.ToLower(s)
	s = strings.ReplaceAll(s, " ", "")
	count := 1
	for i, v := range s {
		if unicode.IsLetter(v) {
			tmp01 := v - 'a'
			result += string(arr[tmp01])
		} else if unicode.IsDigit(v) {
			result += string(v)
		} else {
			continue
		}

		if count%5 == 0 && i < (len(s)-3) {
			result += string(' ')
		}
		count++
	}
	return result
}
