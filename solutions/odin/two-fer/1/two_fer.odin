package two_fer

import "core:strings"
two_fer :: proc(name: string = "you") -> string {
	aa := []string{"One for ", name, ", one for me."}
	return strings.concatenate(aa)
}
