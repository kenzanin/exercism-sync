package anagram

import (
	"sort"
	"strings"
)

func sorts(str string) string {
	tmp := []rune(str)
	sort.Slice(tmp, func(i, j int) bool { return tmp[i] < tmp[j] })
	return string(tmp)
}

func Detect(subject string, candidates []string) []string {
	tmp01 := strings.ToLower(subject)
	first := sorts(tmp01)
	result := []string{}
	for _, s := range candidates {
		second := strings.ToLower(s)
		if first == sorts(second) && tmp01 != second {
			result = append(result, s)
		}
	}
	return result
}
