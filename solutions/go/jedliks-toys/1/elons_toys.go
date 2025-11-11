package elon

import "fmt"

// TODO: define the 'Drive()' method
func (c *Car) Drive() {
	if c.battery-c.batteryDrain < 0 {
		return
	}
	c.distance += c.speed
	c.battery -= c.batteryDrain
}

// TODO: define the 'DisplayDistance() string' method
func (c Car) DisplayDistance() string {
	return "Driven " + fmt.Sprintf("%d", c.distance) + " meters"
}

// TODO: define the 'DisplayBattery() string' method
func (c Car) DisplayBattery() string {
	return "Battery at " + fmt.Sprintf("%d", c.battery) + "%"
}

// TODO: define the 'CanFinish(trackDistance int) bool' method
func (c Car) CanFinish(trackDistance int) bool {
	return c.speed*(c.battery/c.batteryDrain) >= trackDistance
}
