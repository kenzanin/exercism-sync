package anagram

import "core:slice"
import "core:strings"
import "core:unicode/utf8"

process :: proc(word: string) -> []rune {
	// Normalise to lowercase runes, then sort.
	lower, _ := strings.to_lower(word)
	defer delete(lower)

	count := utf8.rune_count(lower)
	runes := make([]rune, count)

	j := 0
	for r in lower {
		runes[j] = r
		j += 1
	}

	slice.sort(runes)
	return runes
}

find_anagrams :: proc(word: string, candidates: []string) -> []string {
	norm_src := process(word)
	defer delete(norm_src)

	matches := [dynamic]string{}
	for cand in candidates {
		if strings.equal_fold(word, cand) do continue // same word -> not an anagram

		norm_cand := process(cand)
		if len(norm_cand) == len(norm_src) {
			same := true
			for i in 0 ..< len(norm_src) {
				if norm_src[i] != norm_cand[i] {
					same = false
					break
				}
			}
			if same do append(&matches, cand)
		}
		delete(norm_cand)
	}

	return matches[:]
}
