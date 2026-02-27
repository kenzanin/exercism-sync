package bottle_song

import "core:fmt"
import "core:strings"

recite :: proc(start_bottles, take_down: int) -> []string {
	//result := make([]string, 0)
	result := [dynamic]string{}
	current := start_bottles
	for i in 0 ..< take_down {
		num_str := bottle_word(current)
		bottle := ""
		if num_str != "One" {
			bottle = "s"
		}
		line := fmt.aprintf("%s green bottle%s hanging on the wall,", num_str, bottle)
		append(&result, line)
		append(&result, line)
		append(&result, "And if one green bottle should accidentally fall,")

		next := current - 1
		if next == 0 {
			append(&result, "There'll be no green bottles hanging on the wall.")
		} else {
			next_str := strings.to_lower(bottle_word(next))
			bottle := ""
			if next_str != "one" {
				bottle = "s"
			}
			append(
				&result,
				fmt.aprintf(
					"There'll be %s green bottle%s hanging on the wall.",
					next_str,
					bottle,
				),
			)
		}
		current -= 1

		if i < take_down - 1 {
			append(&result, "")
		}
	}
	return result[:]
}

bottle_word :: proc(n: int) -> string {
	switch n {
	case 1:
		return "One"
	case 2:
		return "Two"
	case 3:
		return "Three"
	case 4:
		return "Four"
	case 5:
		return "Five"
	case 6:
		return "Six"
	case 7:
		return "Seven"
	case 8:
		return "Eight"
	case 9:
		return "Nine"
	case 10:
		return "Ten"
	}
	return {}
}
