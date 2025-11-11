package pangram

import "strings"

func IsPangram(input string) bool {
	input = strings.ToLower(input)
	for i := 'a'; i <= 'z'; i++ {
		old := len(input)
		input = strings.Replace(input, string(i), "", 1)
		if len(input) == old {
			return false
		}
	}
	return true
}
