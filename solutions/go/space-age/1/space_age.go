package space

import "strings"

type Planet string

func Age(seconds float64, planet Planet) float64 {

	planet = Planet(strings.ToLower(string(planet)))
	timeMap := map[Planet]float64{
		/*
			     - Mercury: orbital period 0.2408467 Earth years
				   - Venus: orbital period 0.61519726 Earth years
				   - Earth: orbital period 1.0 Earth years, 365.25 Earth days, or 31557600 seconds
				   - Mars: orbital period 1.8808158 Earth years
				   - Jupiter: orbital period 11.862615 Earth years
				   - Saturn: orbital period 29.447498 Earth years
				   - Uranus: orbital period 84.016846 Earth years
				   - Neptune: orbital period 164.79132 Earth years
		*/
		"mercury": 31557600 * 0.2408467,
		"venus":   31557600 * 0.61519726,
		"earth":   31557600 * 1.0,
		"mars":    31557600 * 1.8808158,
		"jupiter": 31557600 * 11.862615,
		"saturn":  31557600 * 29.447498,
		"uranus":  31557600 * 84.016846,
		"neptune": 31557600 * 164.79132,
	}
	if timeMap[planet] == 0.0 {
		return -1.0
	}

	return seconds / timeMap[planet]
}
