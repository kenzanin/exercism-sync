package secret

func Handshake(code uint) []string {
	result := []string{}
	if code&0b1 != 0 {
		result = append(result, "wink")
	}
	if code&0b10 != 0 {
		result = append(result, "double blink")
	}
	if code&0b100 != 0 {
		result = append(result, "close your eyes")
	}
	if code&0b1000 != 0 {
		result = append(result, "jump")
	}
	if code&0b10000 != 0 {
		tmp01 := []string{}
		for _, i := range result {
			tmp01 = append([]string{i}, tmp01...)
		}
		result = tmp01
	}
	return result
}
