package clock

import "fmt"

// Define the Clock type here.
type Clock struct {
	h int
	m int
}

func New(h, m int) Clock {
	all := (h * 60) + m
	all = all % (24 * 60)
	if all <= 0 {
		all = ((24 * 60) + all) % (24 * 60)
	}
	return Clock{
		all / 60, all % 60,
	}
}

func (c Clock) Add(m int) Clock {
	all := ((c.h * 60) + c.m) + m
	all = all % (24 * 60)
	if all <= 0 {
		all = ((24 * 60) + all) % (24 * 60)
	}
	return Clock{
		all / 60, all % 60,
	}
}

func (c Clock) Subtract(m int) Clock {
	all := ((c.h * 60) + c.m) - m
	all = all % (24 * 60)
	if all <= 0 {
		all = ((24 * 60) + all) % (24 * 60)
	}
	return Clock{
		all / 60, all % 60,
	}
}

func (c Clock) String() string {
	result := fmt.Sprintf("%02d:%02d", c.h, c.m)
	return result
}
