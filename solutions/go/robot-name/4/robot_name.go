package robotname

import (
	"fmt"
	"math/rand"
	"time"
)

const charset string = "ABCDEFGHIJKLMNOPQRSTUWXZY"

var names = make(map[string]int)

// Define the Robot type here.
type Robot struct {
	name string
}

func (r *Robot) Name() (string, error) {
	if r.name != "" {
		return r.name, nil
	}
	rand.Seed(time.Now().UnixNano())

	for {
		r.name = fmt.Sprintf("%c%c%03d",
			charset[rand.Intn(len(charset))],
			charset[rand.Intn(len(charset))],
			rand.Intn(1000))
		names[r.name]++
		if names[r.name] == 1 {
			break
		}
	}
	return r.name, nil
}

func (r *Robot) Reset() {
	r.name = ""
	names = map[string]int{}
}
