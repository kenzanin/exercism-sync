package reverse_string

import "core:strings"
import "core:unicode/utf8"

reverse :: proc(str: string) -> string {
	sb := strings.builder_make()
	
	grapheme_infos := make([dynamic]utf8.Grapheme)
	defer delete(grapheme_infos)
	
	iter := utf8.decode_grapheme_iterator_make(str)
	for {
		_, grapheme, ok := utf8.decode_grapheme_iterate(&iter)
		if !ok do break
		append(&grapheme_infos, grapheme)
	}
	
	clusters := make([dynamic]string)
	defer delete(clusters)
	
	for i := 0; i < len(grapheme_infos); i += 1 {
		start := grapheme_infos[i].byte_index
		end: int
		if i + 1 < len(grapheme_infos) {
			end = grapheme_infos[i + 1].byte_index
		} else {
			end = len(str)
		}
		append(&clusters, str[start:end])
	}
	
	for i := len(clusters) - 1; i >= 0; i -= 1 {
		strings.write_string(&sb, clusters[i])
	}
	
	return strings.to_string(sb)
}
