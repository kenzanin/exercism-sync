package resistorcolor

var resistor = map[string]int{
	"black":  0,
	"brown":  1,
	"red":    2,
	"orange": 3,
	"yellow": 4,
	"green":  5,
	"blue":   6,
	"violet": 7,
	"grey":   8,
	"white":  9,
}

// Colors should return the list of all colors.
func Colors() []string {
	result := []string{}
	for c := range resistor {
		result = append(result, c)
	}
	return result
}

// ColorCode returns the resistance value of the given color.
func ColorCode(color string) int {
	return resistor[color]
}
