package expenses

import "errors"

// Record represents an expense record.
type Record struct {
	Day      int
	Amount   float64
	Category string
}

// DaysPeriod represents a period of days for expenses.
type DaysPeriod struct {
	From int
	To   int
}

// Filter returns the records for which the predicate function returns true.
func Filter(in []Record, predicate func(Record) bool) []Record {
	tmp := []Record{}
	for i := range in {
		if predicate(in[i]) {
			tmp = append(tmp, in[i])
		}
	}
	return tmp
}

// ByDaysPeriod returns predicate function that returns true when
// the day of the record is inside the period of day and false otherwise.
func ByDaysPeriod(p DaysPeriod) func(Record) bool {
	return func(r Record) bool {
		if r.Day >= p.From && r.Day <= p.To {
			return true
		}
		return false
	}
}

// ByCategory returns predicate function that returns true when
// the category of the record is the same as the provided category
// and false otherwise.
func ByCategory(c string) func(Record) bool {
	return func(r Record) bool {
		return r.Category == c
	}
}

// TotalByPeriod returns total amount of expenses for records
// inside the period p.
func TotalByPeriod(in []Record, p DaysPeriod) float64 {
	tmp := Filter(in, ByDaysPeriod(p))
	result := 0.0
	for _, v := range tmp {
		result += v.Amount
	}
	return result
}

// CategoryExpenses returns total amount of expenses for records
// in category c that are also inside the period p.
// An error must be returned only if there are no records in the list that belong
// to the given category, regardless of period of time.
func CategoryExpenses(in []Record, p DaysPeriod, c string) (float64, error) {
	tmp := Filter(in, ByDaysPeriod(p))
	if len(tmp) == 0 {
		return 0.0, nil
	}
	tmp = Filter(tmp, ByCategory(c))
	if len(tmp) == 0 {
		return 0.0, errors.New("error")
	}
	result := 0.0
	for _, v := range tmp {
		result += v.Amount
	}
	return result, nil
}
