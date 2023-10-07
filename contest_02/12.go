package main

import "fmt"

func fill(maze [][]int) {
	rows := len(maze)
	cols := len(maze[0])

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if maze[i][j] != -1 {
				count := 0
				for dx := -1; dx <= 1; dx++ {
					for dy := -1; dy <= 1; dy++ {
						ni, nj := i+dx, j+dy
						if ni >= 0 && ni < rows && nj >= 0 && nj < cols {
							if maze[ni][nj] == -1 {
								count++
							}
						}
					}
				}
				maze[i][j] = count
			}
		}
	}
}
func main() {
	var rows, cols int
	fmt.Scanf("%d %d\n", &rows, &cols)

	maze := make([][]int, rows, rows)
	for i := range maze {
		maze[i] = make([]int, cols, cols)
		for j := range maze[i] {
			fmt.Scanf("%d", &maze[i][j])
		}
	}

	fill(maze)

	for _, row := range maze {
		for _, cell := range row {
			fmt.Printf("%3d", cell)
		}
		fmt.Println()
	}
}
