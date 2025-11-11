package parsinglogfiles

import (
	"fmt"
	"regexp"
)

func IsValidLine(text string) bool {
	re := regexp.MustCompile(`^\[(TRC|DBG|ERR|INF)\]`)
	return re.MatchString(text)
}

func SplitLogLine(text string) []string {
	re := regexp.MustCompile(`<[-=~*]*>`)
	result := re.Split(text, -1)
	return result
}

func CountQuotedPasswords(lines []string) int {
	re := regexp.MustCompile(`(?i)(".*password.*")`)
	count := 0
	for _, v := range lines {
		if re.MatchString(v) {
			count++
		}
	}
	return count
}

func RemoveEndOfLineText(text string) string {
	re := regexp.MustCompile(`end-of-line\d*`)
	return re.ReplaceAllString(text, "")
}

func TagWithUserName(lines []string) []string {
	re := regexp.MustCompile(`User\s+(\w+)`)
	result := []string{}
	for _, v := range lines {
		tmp := re.FindStringSubmatch(v)
		if tmp != nil {
			v = fmt.Sprintf("[USR] %s %s", tmp[1], v)
		}
		result = append(result, v)
	}
	return result
}
