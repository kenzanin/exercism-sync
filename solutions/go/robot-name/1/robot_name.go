package robotname

import (
	"fmt"
	"math/rand"
	"time"
)

// Define the Robot type here.
type Robot struct {
	name string
}

func (r *Robot) Name() (string, error) {
	if r.name != "" {
		return r.name, nil
	}
	const charset = "ABCDEFGHIJKLMNOPQRSTUWXZY"
	rand.Seed(time.Now().UnixNano())
	r.name = fmt.Sprintf("%c%c%03d",
		charset[rand.Intn(len(charset))],
		charset[rand.Intn(len(charset))], rand.Intn(1000))
	return r.name, nil
}

func (r *Robot) Reset() {
	r.name = ""
}
