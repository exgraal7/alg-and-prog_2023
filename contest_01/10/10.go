package main

import "fmt"

func main() {
	var swim, wings, neck string
	fmt.Scan(&swim, &wings, &neck)

	if swim == "Да" && wings == "Да" && neck == "Да" {
		fmt.Println("Утка")
	} else if swim == "Да" && wings == "Да" {
		fmt.Println("Пингвин")
	} else if swim == "Да" && neck == "Да" {
		fmt.Println("Плезиозавры")
	} else if swim == "Да" {
		fmt.Println("Дельфин")
	} else if wings == "Да" && neck == "Да" {
		fmt.Println("Страус")
	} else if wings == "Да" {
		fmt.Println("Курица")
	} else if neck == "Да" {
		fmt.Println("Жираф")
	} else {
		fmt.Println("Кот")
	}
}
