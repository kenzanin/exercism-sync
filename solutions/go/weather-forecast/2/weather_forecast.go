// Package weather this is description.
package weather

// CurrentCondition this is description.
var CurrentCondition string

// CurrentLocation CurrentLocation.
var CurrentLocation string

// Forecast with param
// - city as string
// - condition as string
// and return
// - weather condition as string.
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}
