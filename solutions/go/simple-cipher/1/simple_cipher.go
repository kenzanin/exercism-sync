package cipher

import (
	"math"
	"strings"
	"unicode"
)

// Define the shift and vigenere types here.
// Both types should satisfy the Cipher interface.
type shift struct {
	distance byte
}

type vigenere struct {
	key []byte
}

func NewCaesar() Cipher {
	return shift{distance: 3}
}

func NewShift(distance int) Cipher {
	if math.Abs(float64(distance)) >= 26 || distance == 0 {
		return nil
	}
	return shift{distance: byte(distance)}
}

func char_helper(c rune, distance byte) (byte, bool) {
	if !unicode.IsLetter(c) || unicode.IsPunct(c) {
		return 0, false
	}

	cc := byte(unicode.ToLower(c))
	result := cc + distance
	if result > 'z' {
		result -= 'z'
		result += ('a' - 1)
	} else if result < 'a' {
		result = 'a' - result
		result = 'z' - (result - 1)
	}
	return result, true
}

func string_helper(distance byte, input string) string {
	in := strings.ToLower(input)
	result := []byte{}
	for _, i := range in {
		if ii, ok := char_helper(i, distance); ok {
			result = append(result, ii)
		}
	}
	return string(result)
}

func (c shift) Encode(input string) string {
	if len(input) == 0 {
		return ""
	}
	return string_helper(c.distance, input)
}

func (c shift) Decode(input string) string {
	if len(input) == 0 {
		return ""
	}
	return string_helper(-c.distance, input)
}

func NewVigenere(key string) Cipher {
	if len(key) < 4 || strings.ContainsAny(key, " ,") {
		return nil
	}

	result := make([]byte, len(key))
	for i := range result {
		result[i] = key[i] - 'a'
	}
	return vigenere{key: result}
}

func (v vigenere) Encode(input string) string {
	result := []byte{}
	index := 0
	for _, ii := range input {
		if c, ok := char_helper(ii, v.key[index]); ok {
			result = append(result, c)
			if index++; index > len(v.key)-1 {
				index = 0
			}
		}
	}
	return string(result)
}

func (v vigenere) Decode(input string) string {
	result := []byte{}
	index := 0
	for _, ii := range input {
		if c, ok := char_helper(ii, -v.key[index]); ok {
			result = append(result, c)
			if index++; index > len(v.key)-1 {
				index = 0
			}
		}
	}
	return string(result)
}
