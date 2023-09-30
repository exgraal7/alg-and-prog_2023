package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	heights := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&heights[i])
	}

	leftMax, rightMax := 0, 0
	left, right := 0, n-1
	water := 0

	for left <= right {
		if heights[left] <= heights[right] {
			if heights[left] >= leftMax {
				leftMax = heights[left]
			} else {
				water += leftMax - heights[left]
			}
			left++
		} else {
			if heights[right] >= rightMax {
				rightMax = heights[right]
			} else {
				water += rightMax - heights[right]
			}
			right--
		}
	}

	fmt.Println(water)
}
