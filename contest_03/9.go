package main

import "fmt"

func findPair(arr []int, target int) (int, int) {
	seen := make(map[int]bool)

	for _, num := range arr {
		complement := target - num
		if seen[complement] {
			return complement, num
		}
		seen[num] = true
	}

	return 0, 0
}

func main() {
	var n, X int
	fmt.Scan(&n, &X)

	numbers := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&numbers[i])
	}

	A, B := findPair(numbers, X)

	if A < B {
		fmt.Println(A, B)
	} else {
		fmt.Println(B, A)
	}
}
