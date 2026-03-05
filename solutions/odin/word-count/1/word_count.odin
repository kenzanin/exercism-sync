package word_count

import "core:strings"

count_word :: proc(input: string) -> map[string]u32 {
	s := strings.to_lower(input)

	s, _ = strings.replace_all(s, "!", " ")
	s, _ = strings.replace_all(s, ".", " ")
	s, _ = strings.replace_all(s, ",", " ")
	s, _ = strings.replace_all(s, ":", " ")
	s, _ = strings.replace_all(s, "&", " ")
	s, _ = strings.replace_all(s, "$", " ")
	s, _ = strings.replace_all(s, "%", " ")
	s, _ = strings.replace_all(s, "^", " ")
	s, _ = strings.replace_all(s, "@", " ")
	s, _ = strings.replace_all(s, "(", " ")
	s, _ = strings.replace_all(s, ")", " ")
	s, _ = strings.replace_all(s, "=", " ")

	words := strings.fields(s)

	result: map[string]u32
	for word in words {
		trimmed := strings.trim(word, "'\"")
		if len(trimmed) > 0 {
			result[trimmed] += 1
		}
	}
	return result
}
