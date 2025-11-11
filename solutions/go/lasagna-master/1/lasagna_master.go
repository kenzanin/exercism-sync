package lasagna

import "sort"

// TODO: define the 'PreparationTime()' function
func PreparationTime(layers []string, time int) int {
	if time == 0 {
		return 4
	}
	return len(layers) * time
}

// TODO: define the 'Quantities()' function
func Quantities(layers []string) (int, float64) {
	noodle := 0
	sauce := 0.0
	for _, v := range layers {
		if v == "sauce" {
			sauce += 0.2
		} else if v == "noodles" {
			noodle += 50
		}
	}
	return noodle, sauce
}

// TODO: define the 'AddSecretIngredient()' function
func AddSecretIngredient(otherList, myList []string) {
	index := 0
	for index = len(otherList) - 1; index >= 0; index-- {
		if sort.SearchStrings(myList, otherList[index]) == 0 {
			break
		}
	}
	myList[len(otherList)] = otherList[index]
}

// TODO: define the 'ScaleRecipe()' function
func ScaleRecipe(quantities []float64, portion int) []float64 {
	return []float64{0.0}
}
