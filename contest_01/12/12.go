package main

import "fmt"

func collatzSteps(x int) int {
	steps := 0
	for x != 1 {
		if x%2 == 0 {
			x = x / 2
		} else {
			x = 3*x + 1
		}
		steps++
	}
	return steps
}

func main() {
	var x int
	fmt.Scan(&x)

	steps := collatzSteps(x)
	fmt.Println(steps)
}
