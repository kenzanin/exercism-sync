package wordcount

import (
	"strings"
)

type Frequency map[string]int

func WordCount(phrase string) Frequency {
	test := " " + phrase + " "

	{
		replace := []string{
			",", " '", "' ", ".", ":", "!",
			"#", "%", "&", "(", ")", "*",
			"+", ",", "^", "@", "$", "\n",
		}
		for _, ii := range replace {
			test = strings.ReplaceAll(test, ii, " ")
		}
	}

	test2 := strings.Split(test, " ")

	result := Frequency{}
	for _, ii := range test2 {
		if ii == "" {
			continue
		}
		result[strings.ToLower(ii)]++
	}

	return result
}
