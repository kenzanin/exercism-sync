package brackets

func Bracket(input string) bool {
	pair := map[rune]rune{
		')': '(',
		']': '[',
		'}': '{',
	}
	bracket := []rune{}
	for _, i := range input {
		switch i {
		case '(', '[', '{':
			bracket = append(bracket, i)
		case ')', ']', '}':
			if len(bracket) == 0 || bracket[len(bracket)-1] != pair[i] {
				return false
			}
			bracket = bracket[:len(bracket)-1]
		default:
		} 
	}
	return len(bracket) == 0
}
