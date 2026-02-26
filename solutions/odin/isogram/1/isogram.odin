package isogram

import "core:strings"
is_isogram :: proc(word: string) -> bool {
	seen := make(map[u8]bool)
	defer delete(seen)
	word_mut := make([]u8, len(word))
	defer delete(word_mut)
	copy(word_mut, word)
	for &c in word_mut {
		if c == ' ' || c == '-' {
			continue
		}
		if c >= 'A' && c <= 'Z' {
			c += 32
		}
		if seen[c] {
			return false
		}
		seen[c] = true
	}
	return true
}
