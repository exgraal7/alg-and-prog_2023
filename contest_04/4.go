package main

import (
	"bufio"
	"encoding/csv"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var targetPclass int
	var targetAge float64
	fmt.Scanln(&targetPclass, &targetAge)

	answer := map[int][]string{}

	file, _ := os.Open("train.csv")
	reader := bufio.NewReader(file)
	reader.ReadString('\r')

	for {
		rLine, err := reader.ReadString('\r')
		if err == io.EOF {
			break
		}
		line, _ := csv.NewReader(strings.NewReader(rLine)).Read()
		pclass, _ := strconv.Atoi(line[2])
		age, _ := strconv.Atoi(line[5])

		if pclass == targetPclass && line[4] == "female" && float64(age) > targetAge {
			answer[age] = append(answer[age], line[3])
		}
	}

	var keys []int
	for k := range answer {
		keys = append(keys, k)
	}
	sort.Ints(keys)

	for _, k := range keys {
		sort.Strings(answer[k])
		for _, name := range answer[k] {
			fmt.Println(name)
		}
	}
}
