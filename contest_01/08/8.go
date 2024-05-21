package main

import "fmt"

func main() {
	var a, b, c, temp_max int
	fmt.Scan(&a, &b, &c)
	if a > b {
		temp_max = a
	} else {
		temp_max = b
	}
	if temp_max > c {
		fmt.Println(temp_max)
	} else {
		fmt.Println(c)
	}
}
