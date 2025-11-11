package hamming

import "errors"

func Distance(a, b string) (int, error) {
	if len(a) == 0 && len(b) == 0 {
		return 0, nil
	} else if len(a) != len(b) || len(a) == 0 || len(b) == 0 {
		return 0, errors.New("")
	}

	count := 0
	for i, v := range a {
		if v != []rune(b)[i] {
			count++
		}
	}
	return count, nil
}
