// This is a "stub" file.  It's a little start on your solution.
// It's not a complete solution though; you have to write some code.

// Package triangle should have a package comment that summarizes what it's about.
// https://golang.org/doc/effective_go.html#commentary
package triangle

import "math"

// Notice KindFromSides() returns this type. Pick a suitable data type.
type Kind int

const (
  // Pick values for the following identifiers used by the test program.
  NaT Kind = iota // not a triangle
  Equ             // equilateral
  Iso             // isosceles
  Sca             // scalene
)

// KindFromSides should have a comment documenting it.
func KindFromSides(a, b, c float64) Kind {
  if (a+b+c == 0) || (a+b+c != math.Abs(a)+math.Abs(b)+math.Abs(c)) {
    return NaT
  }
  if a+b > c && a+c > b && b+c > a {
    if a == b && b == c {
      return Equ
    }
    if (b == c) != (a == c) != (a == b) {
      return Iso
    }
    if a != b && b != c && c != a {
      return Sca
    }
  }
  return NaT
}
