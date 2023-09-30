package main

import "fmt"

func smoothData(n int, measurements []int) []float64 {
	smoothed := make([]float64, n)

	smoothed[0] = float64(measurements[0])
	smoothed[n-1] = float64(measurements[n-1])

	for i := 1; i < n-1; i++ {
		smoothed[i] = float64(measurements[i-1]+measurements[i]+measurements[i+1]) / 3
	}

	return smoothed
}

func main() {
	var n int
	fmt.Scan(&n)

	measurements := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&measurements[i])
	}

	smoothed := smoothData(n, measurements)

	for i := 0; i < n; i++ {
		fmt.Printf("%.10f ", smoothed[i])
	}
	fmt.Println()
}
