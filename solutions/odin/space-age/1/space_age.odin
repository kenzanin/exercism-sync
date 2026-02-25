package space_age

Planet :: enum {
	Mercury,
	Venus,
	Earth,
	Mars,
	Jupiter,
	Saturn,
	Uranus,
	Neptune,
}

age :: proc(planet: Planet, seconds: int) -> f64 {
	periods := [8]f64 {
		0.2408467 * 31_557_600.0,
		0.61519726 * 31_557_600.0,
		1.0 * 31_557_600.0,
		1.8808158 * 31_557_600.0,
		11.862615 * 31_557_600.0,
		29.447498 * 31_557_600.0,
		84.016846 * 31_557_600.0,
		164.79132 * 31_557_600.0,
	}
	return f64(seconds) / periods[int(planet)]
}
