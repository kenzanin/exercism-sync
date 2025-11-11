package allergies

func Allergies(allergies uint) []string {
	allergiesMap := map[int]string{
		/*
		* eggs (1)
		* peanuts (2)
		* shellfish (4)
		* strawberries (8)
		* tomatoes (16)
		* chocolate (32)
		* pollen (64)
		* cats (128)
		 */

		1:   "eggs",
		2:   "peanuts",
		4:   "shellfish",
		8:   "strawberries",
		16:  "tomatoes",
		32:  "chocolate",
		64:  "pollen",
		128: "cats",
	}

	result := []string{}
	for i := 1; i <= int(allergies) && i <= 128; i <<= 1 {
		if allergies&uint(i) > 0 {
			result = append(result, allergiesMap[i])
		}
	}
	return result
}

func AllergicTo(allergies uint, allergen string) bool {
	for _, v := range Allergies(allergies) {
		if v == allergen {
			return true
		}
	}
	return false
}
