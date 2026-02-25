package all_your_base

import "core:slice"
Error :: enum {
	None,
	Invalid_Input_Digit,
	Input_Base_Too_Small,
	Output_Base_Too_Small,
	Unimplemented,
}

rebase :: proc(input_base: int, digits: []int, output_base: int) -> ([]int, Error) {
	if input_base < 2 {
		return nil, .Input_Base_Too_Small
	}
	if output_base < 2 {
		return nil, .Output_Base_Too_Small
	}

	value := 0
	for i in digits {
		if i < 0 || i >= input_base {
			return nil, .Invalid_Input_Digit
		}
		value = value * input_base + i
	}

	if value == 0 {
		result := make([]int, 1)
		result[0] = 0
		return result, .None
	}

	output_digits: [dynamic]int
	for value > 0 {
		rem := value % output_base
		append(&output_digits, rem)
		value = value / output_base
	}

	slice.reverse(output_digits[:])

	result := make([]int, len(output_digits))
	copy(result, output_digits[:])
	delete(output_digits)

	return result, .None
}
