package robotname

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

// Define the Robot type here.
type Robot struct {
	name string
}

const charset string = "ABCDEFGHIJKLMNOPQRSTUWXZY"

func (r *Robot) Name() (string, error) {
	w := sync.Mutex{}
	if r.name != "" {
		return r.name, nil
	}
	w.Lock()
	time.Sleep(100 * time.Microsecond)
	rand.Seed(time.Now().UnixNano())
	w.Unlock()
	r.name = fmt.Sprintf("%c%c%03d",
		charset[rand.Intn(len(charset))],
		charset[rand.Intn(len(charset))],
		rand.Intn(1000))

	return r.name, nil
}

func (r *Robot) Reset() {
	r.name = ""
}
