package tournament

import (
	"errors"
	"fmt"
	"io"
	"io/ioutil"
	"strings"
)

type score_ struct {
	play int
	won  int
	lost int
	draw int
}

func (t score_) point() int {
	return (t.won * 3) + t.draw
}

func Tally(reader io.Reader, writer io.Writer) error {
	var teams = map[string]score_{
		"Devastating Donkeys":     {},
		"Allegoric Alaskians":     {},
		"Blithering Badgers":      {},
		"Courageous Californians": {},
	}

	content_, _ := ioutil.ReadAll(reader)
	content := strings.Split(string(content_), "\n")
	for _, i := range content {
		ii := strings.Split(i, ";")
		if len(ii) < 3 {
			continue
		}

		score01, ok01 := teams[ii[0]]
		score02, ok02 := teams[ii[1]]
		if !ok01 || !ok02 {
			return errors.New("")
		}

		score01.play += 1
		score02.play += 1
		switch ii[2] {
		case "win":
			score01.won += 1
			score02.lost += 1
			break
		case "loss":
			score01.lost += 1
			score02.won += 1
			break
		case "draw":
			score01.draw += 1
			score02.draw += 1
			break
		default:
			return errors.New("")
		}
		teams[ii[0]] = score01
		teams[ii[1]] = score02
	}

	result := "Team                           | MP |  W |  D |  L |  P\n"
	t := teams["Devastating Donkeys"]
	result += fmt.Sprintf("%-31s|  %d |  %d |  %d |  %d |  %d\n", "Devastating Donkeys", t.play, t.won, t.draw, t.lost, t.point())
	t = teams["Allegoric Alaskians"]
	result += fmt.Sprintf("%-31s|  %d |  %d |  %d |  %d |  %d\n", "Allegoric Alaskians", t.play, t.won, t.draw, t.lost, t.point())
	t = teams["Blithering Badgers"]
	result += fmt.Sprintf("%-31s|  %d |  %d |  %d |  %d |  %d\n", "Blithering Badgers", t.play, t.won, t.draw, t.lost, t.point())
	t = teams["Courageous Californians"]
	result += fmt.Sprintf("%-31s|  %d |  %d |  %d |  %d |  %d", "Courageous Californians", t.play, t.won, t.draw, t.lost, t.point())

	io.WriteString(writer, result)
	return nil
}
