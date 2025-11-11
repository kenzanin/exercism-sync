// this is Package for weather
package weather

// hold current condition
var CurrentCondition string

// hold current location
var CurrentLocation string

// function Forecast with param
// - city as string
// - condition as string
// and return
// - weather condition as string
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}
