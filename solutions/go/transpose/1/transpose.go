package transpose

func Transpose(input []string) []string {
	str_len := 0
	for _, i := range input {
		if len(i) > str_len {
			str_len = len(i)
		}
	}
	result := make([]string, str_len)
	for _, ii := range input {
		for i, iii := range ii {
			result[i] += string(iii)
		}
		// fill with space
		for i := len(ii); i < len(result); i++ {
			result[i] += " "
		}
	}
	// clear remaining space
	for _, ii := range input {
		for iii := len(ii); iii < len(result); iii++ {
			if result[iii][len(result[iii])-1] == ' ' {
				result[iii] = result[iii][0 : len(result[iii])-1]
			}
		}
	}
	return result
}
