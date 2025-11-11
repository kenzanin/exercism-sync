package encode

import (
	"strconv"
	"strings"
	"unicode"
)

type rle_s struct {
	ch    byte
	count int
}

func RunLengthEncode(input string) string {
	test := []rle_s{}

	var prev rune
	for _, ii := range input {
		if prev == ii {
			test[len(test)-1].count++
		} else {
			test = append(test, rle_s{byte(ii), 1})
		}
		prev = ii
	}

	result := []byte{}
	for _, ii := range test {
		if ii.count == 1 {
			result = append(result, ii.ch)
		} else {
			var01 := []byte(strconv.Itoa(ii.count))
			result = append(result, var01...)
			result = append(result, ii.ch)
		}
	}
	return string(result)
}

func RunLengthDecode(input string) string {
	number := []byte{}
	result := ""
	for _, ii := range input {
		if unicode.IsNumber(ii) {
			number = append(number, byte(ii))
			continue
		} else {
			ch := string(ii)
			str := ""
			if num, ok := strconv.Atoi(string(number)); ok == nil {
				str = strings.Repeat(ch, num)
				number = []byte{}
			} else {
				str = ch
			}
			result += str
		}
	}
	return result
}
