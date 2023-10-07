package main

import (
	"bufio"
	"fmt"
	"os"
)

func isLucky(number string) bool {
	if len(number) != 6 {
		return false
	}

	firstHalf := number[:3]
	secondHalf := number[3:]

	sumFirstHalf := 0
	sumSecondHalf := 0

	for _, digit := range firstHalf {
		if digit < '0' || digit > '9' {
			return false
		}
		sumFirstHalf += int(digit - '0')
	}

	for _, digit := range secondHalf {
		if digit < '0' || digit > '9' {
			return false
		}
		sumSecondHalf += int(digit - '0')
	}

	return sumFirstHalf == sumSecondHalf
}
func main() {
	number, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isLucky(number[:len(number)-1]) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
