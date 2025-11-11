package reverse

func Reverse(input string) string {
	result := []rune{}
	for _, v := range input {
		result = append([]rune{v}, result...)
	}
	return string(result)
}
