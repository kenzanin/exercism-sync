package school

import (
	"sort"
)

// Define the Grade and School types here.
type Grade struct {
	grade    int
	students []string
}

type School struct {
	all []Grade
}

func New() *School {
	new := School{}
	return &new
}

func (s *School) Add(student string, grade int) {
	exist := false
	for i := range s.all {
		if s.all[i].grade == grade {
			s.all[i].students = append(s.all[i].students, student)
			exist = true
			break
		}
	}
	if !exist {
		s.all = append(s.all, Grade{grade: grade, students: []string{student}})
	}
}

func (s *School) Grade(level int) []string {
	for i := range s.all {
		if s.all[i].grade == level {
			return s.all[i].students
		}
	}
	return []string{}
}

func (s *School) Enrollment() []Grade {
	sort.Slice(s.all, func(i, j int) bool {
		return s.all[i].grade < s.all[j].grade
	})
	for i := range s.all {
		sort.Strings(s.all[i].students)
	}

	return s.all
}
