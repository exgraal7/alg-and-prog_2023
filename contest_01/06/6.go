package main

import "fmt"

func countBills(N int, denomination int) (int, int) {
	numBills := N / denomination
	remaining := N % denomination
	return numBills, remaining
}

func main() {
	var N, FiveThousand, OneThousand, FiveHundred, TwoHundred, OneHundred int
	fmt.Scan(&N)

	FiveThousand, N = countBills(N, 5000)
	OneThousand, N = countBills(N, 1000)
	FiveHundred, N = countBills(N, 500)
	TwoHundred, N = countBills(N, 200)
	OneHundred, _ = countBills(N, 100)

	fmt.Println(FiveThousand, OneThousand, FiveHundred, TwoHundred, OneHundred)
}
