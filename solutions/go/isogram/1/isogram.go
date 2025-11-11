package isogram

import "strings"

func IsIsogram(word string) bool {
	arrWord := []rune(strings.ToLower(word))

	for i := 0; i < len(arrWord)-1; i++ {
		if arrWord[i] == '-' || arrWord[i] == ' ' {
			continue
		}
		for ii := i + 1; ii < len(arrWord); ii++ {
			if arrWord[i] == arrWord[ii] {
				return false
			}
		}
	}
	return true
}
