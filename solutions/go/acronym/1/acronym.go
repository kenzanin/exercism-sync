// This is a "stub" file.  It's a little start on your solution.
// It's not a complete solution though; you have to write some code.

// Package acronym should have a package comment that summarizes what it's about.
// https://golang.org/doc/effective_go.html#commentary
package acronym

import (
	"regexp"
	"strings"
)

// Abbreviate yes
func Abbreviate(s string) string {
	space := regexp.MustCompile(`-+|_+`)
	s = space.ReplaceAllString(s, " ")
	space = regexp.MustCompile(`\s+`)
	s = space.ReplaceAllString(s, " ")
	result := strings.Split(s, " ")
	tmp := ""
	for i := 0; i < len(result); i++ {
		tmp += strings.ToUpper(string(result[i][0]))
	}
	return tmp
}
