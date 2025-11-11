package blackjack

// ParseCard returns the integer value of a card following blackjack ruleset.
func ParseCard(card string) int {
	tmp := map[string]int{
		"ace":   11,
		"two":   2,
		"three": 3,
		"four":  4,
		"five":  5,
		"six":   6,
		"seven": 7,
		"eight": 8,
		"nine":  9,
		"ten":   10,
		"jack":  10,
		"queen": 10,
		"king":  10,
	}
	if tmp[card] == 0 {
		return 0
	}
	return tmp[card]
}

// FirstTurn returns the decision for the first turn, given two cards of the
// player and one card of the dealer.
func FirstTurn(card1, card2, dealerCard string) string {
	score := ParseCard(card1) + ParseCard(card2)
	dealer := ParseCard(dealerCard)

	switch score {
	case 22:
		{
			return "P"
		}
	case 21:
		{
			if dealer < 10 {
				return "W"
			} else {
				return "S"
			}
		}
	case 17, 18, 19, 20:
		{
			return "S"
		}
	case 12, 13, 14, 15, 16:
		{
			if dealer >= 7 {
				return "H"
			} else {
				return "S"
			}
		}
	default:
		{
			return "H"
		}
	}
}
