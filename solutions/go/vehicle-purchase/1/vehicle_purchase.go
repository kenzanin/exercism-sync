package purchase

import "strings"

// NeedsLicense determines whether a license is needed to drive a type of vehicle. Only "car" and "truck" require a license.
func NeedsLicense(kind string) bool {
	switch kind {
	case "car", "truck":
		return true
	default:
		return false
	}
}

// ChooseVehicle recommends a vehicle for selection. It always recommends the vehicle that comes first in lexicographical order.
func ChooseVehicle(option1, option2 string) string {
	tmp01 := strings.Split(option1, " ")
	tmp02 := strings.Split(option2, " ")
	result := " "

	if tmp01[0][0] < tmp02[0][0] {
		result = option1
	} else if tmp01[0][0] > tmp02[0][0] {
		result = option2
	} else if tmp01[0][0] == tmp02[0][0] {
		if tmp01[1][0] < tmp02[1][0] {
			result = option1
		} else {
			result = option2
		}
	}

	return result + " is clearly the better choice."
}

// CalculateResellPrice calculates how much a vehicle can resell for at a certain age.
func CalculateResellPrice(originalPrice, age float64) float64 {
	switch {
	case age <= 3:
		return 0.8 * originalPrice
	case age >= 10:
		return 0.5 * originalPrice
	default:
		return 0.7 * originalPrice
	}
}
