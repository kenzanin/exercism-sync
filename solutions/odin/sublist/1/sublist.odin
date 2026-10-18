package sublist

import "core:slice"

Comparison :: enum {
	Unimplemented,
	Equal,
	Sublist,
	Superlist,
	Unequal,
}

// True when `needle` appears as a contiguous run inside `haystack`.
_contains :: proc(haystack, needle: []$T) -> bool {
	if len(needle) == 0 do return true
	if len(needle) > len(haystack) do return false

	for i in 0 ..= len(haystack) - len(needle) {
		if slice.equal(haystack[i:i + len(needle)], needle) do return true
	}
	return false
}

compare :: proc(list_a: []$T, list_b: []T) -> Comparison {
	if slice.equal(list_a, list_b) do return .Equal

	// Equal length is already settled: the contents differ.
	if len(list_a) == len(list_b) do return .Unequal

	if len(list_a) < len(list_b) {
		if _contains(list_b, list_a) do return .Sublist
	} else if _contains(list_a, list_b) {
		return .Superlist
	}

	return .Unequal
}
