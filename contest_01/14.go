package main

import "fmt"

func main() {
	var row, col int

	fmt.Scan(&row, &col)

	fmt.Print("    |")

	for i := 1; i <= col; i++ {
		intend(i)
		fmt.Print(i)
	}

	fmt.Print("\n   --")

	for i := 1; i <= col; i++ {
		fmt.Print("----")
	}
	fmt.Print("\n")

	for i := 1; i <= row; i++ {
		intend(i)
		fmt.Print(i, "|")
		for j := 1; j <= col; j++ {
			intend(i * j)
			fmt.Print(i * j)
		}
		fmt.Println()
	}
}

func intend(n int) {
	switch {
	case n < 10:
		fmt.Print("   ")
	case n < 100:
		fmt.Print("  ")
	default:
		fmt.Print(" ")
	}
}
