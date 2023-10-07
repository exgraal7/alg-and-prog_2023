package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

func isPalindrome(s string) bool {
	s = strings.ToLower(s)

	cleaned := make([]rune, 0, len(s))
	for _, char := range s {
		if unicode.IsLetter(char) || unicode.IsDigit(char) {
			cleaned = append(cleaned, char)
		}
	}

	length := len(cleaned)
	for i := 0; i < length/2; i++ {
		if cleaned[i] != cleaned[length-1-i] {
			return false
		}
	}

	return true
}
func main() {
	line, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isPalindrome(line[:len(line)-1]) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
