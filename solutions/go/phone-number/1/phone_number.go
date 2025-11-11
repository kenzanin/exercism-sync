package phonenumber

import (
	"errors"
	"regexp"
)

func Number(phoneNumber string) (string, error) {
	if phoneNumber == "" {
		return "", errors.New("")
	}

	reg := regexp.MustCompile("([^0-9]+)")
	phoneNumber = reg.ReplaceAllString(phoneNumber, "")

	if len(phoneNumber) == 11 {
		if phoneNumber[0] == '1' {
			phoneNumber = phoneNumber[1:]
			if phoneNumber[0] == '0' || phoneNumber[0] == '1' || phoneNumber[3] == '0' || phoneNumber[3] == '1' {
				return "", errors.New("")
			}
			return phoneNumber, nil
		}
	} else if len(phoneNumber) == 10 {
		if phoneNumber[0] == '0' || phoneNumber[0] == '1' || phoneNumber[3] == '0' || phoneNumber[3] == '1' {
			return "", errors.New("")
		}
		return phoneNumber, nil
	}

	return "", errors.New("")
}

func AreaCode(phoneNumber string) (string, error) {
	result, err := Number(phoneNumber)
	if err == nil {
		return result[0:3], err
	}
	return "", err
}

func Format(phoneNumber string) (string, error) {
	result, err := Number(phoneNumber)
	if err != nil {
		return "", errors.New("")
	}

	result = "(" + result[0:3] + ") " + result[3:6] + "-" + result[6:]
	return result, nil
}
