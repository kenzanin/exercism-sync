package brackets

func Bracket(input string) bool {
	bracket := []rune{}
	for _, i := range input {
		switch i {
		case '(':
			fallthrough
		case '[':
			fallthrough
		case '{':
			bracket = append(bracket, i)
		case ')':
			if len(bracket) == 0 {
				return false
			}
			if bracket[len(bracket)-1] == rune('(') {
				bracket = bracket[:len(bracket)-1]
			} else {
				return false
			}
		case ']':
			if len(bracket) == 0 {
				return false
			}
			if bracket[len(bracket)-1] == rune('[') {
				bracket = bracket[:len(bracket)-1]
			} else {
				return false
			}
		case '}':
			if len(bracket) == 0 {
				return false
			}
			if bracket[len(bracket)-1] == rune('{') {
				bracket = bracket[:len(bracket)-1]
			} else {
				return false
			}
		default:
		}
	}
	return len(bracket) == 0
}
