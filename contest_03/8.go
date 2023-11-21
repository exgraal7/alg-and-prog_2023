package main

import (
	"fmt"
)

func findNumberWithoutPair(arr []int) int {
	result := 0
	for _, num := range arr {
		result ^= num
	}
	return result
}

func main() {
	var n int
	fmt.Scan(&n)
	numbers := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&numbers[i])
	}

	uniqueNumber := findNumberWithoutPair(numbers)
	fmt.Println(uniqueNumber)
}
