package meteorology

import "fmt"

type TemperatureUnit int

const (
	Celsius    TemperatureUnit = 0
	Fahrenheit TemperatureUnit = 1
)

// Add a String method to the TemperatureUnit type
func (tpu *TemperatureUnit) String() string {
	tmp := []string{"°C", "°F"}
	return tmp[*tpu]
}

type Temperature struct {
	degree int
	unit   TemperatureUnit
}

// Add a String method to the Temperature type
func (temp *Temperature) String() string {
	return fmt.Sprintf("%d %s", temp.degree, &temp.unit)
}

type SpeedUnit int

const (
	KmPerHour    SpeedUnit = 0
	MilesPerHour SpeedUnit = 1
)

// Add a String method to SpeedUnit
func (spu *SpeedUnit) String() string {
	tmp := []string{"km/h", "mph"}
	return tmp[*spu]
}

type Speed struct {
	magnitude int
	unit      SpeedUnit
}

// Add a String method to Speed
func (sp *Speed) String() string {
	return fmt.Sprintf("%d %s", sp.magnitude, &sp.unit)
}

type MeteorologyData struct {
	location      string
	temperature   Temperature
	windDirection string
	windSpeed     Speed
	humidity      int
}

// Add a String method to MeteorologyData
func (mtrd *MeteorologyData) String() string {
	//San Francisco: 57 °F, Wind NW at 19 mph, 60% Humidity
	return fmt.Sprintf("%s: %s, Wind %s at %s, %d%% Humidity",
		mtrd.location,
		mtrd.temperature.String(),
		mtrd.windDirection,
		mtrd.windSpeed.String(),
		mtrd.humidity,
	)
}
