package romannumerals

import "errors"

func helper(input int, base int) string {
	roman := map[int]string{
		1:    "I",
		4:    "IV",
		5:    "V",
		9:    "IX",
		10:   "X",
		15:   "XV",
		19:   "IX",
		40:   "XL",
		50:   "L",
		90:   "XC",
		100:  "C",
		400:  "CD",
		500:  "D",
		900:  "CM",
		1000: "M",
	}

	result := ""
	i := input % (base * 10)
	i = (i / base) * base
	for i > 0 {
		ii, ok := roman[i]
		if ok {
			result = ii + result
			i = 0
		} else {
			result = roman[base] + result
			i -= base
		}
	}
	return result
}

func ToRomanNumeral(input int) (string, error) {
	if input <= 0 || input >= 4000 {
		return "", errors.New("")
	}

	result := ""
	for i := 1; i <= 1000; i *= 10 {
		result = helper(input, i) + result
	}
	return result, nil
}
