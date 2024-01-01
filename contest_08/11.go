package main
import "fmt"

type Matrix struct{
    data [][]int
}

// Начало вставленного кода
func NewMatrix(rows, cols, value int) Matrix {
 matrix := Matrix{}
 for i := 0; i < rows; i++ {
  newRow := make([]int, cols)
  for j := range newRow {
   newRow[j] = value
  }
  matrix.data = append(matrix.data, newRow)
 }
 return matrix
}

func (m *Matrix) Rows() int {
 return len(m.data)
}

func (m *Matrix) Cols() int {
 if len(m.data) > 0 {
  return len(m.data[0])
 }
 return 0
}

func (m *Matrix) Set(row, col, value int) {
 if row >= 0 && row < len(m.data) && col >= 0 && col < len(m.data[row]) {
  m.data[row][col] = value
 }
}

func (m *Matrix) Get(row, col int) int {
 if row >= 0 && row < len(m.data) && col >= 0 && col < len(m.data[row]) {
  return m.data[row][col]
 }
 return 0
}

func (m *Matrix) String() string {
 var result string
 for _, row := range m.data {
  for _, item := range row {
   result += fmt.Sprintf("%d", item) + " "
  }
  result += "\n"
 }
 return result
}

func (m *Matrix) AddRow(value int) {
 newRow := make([]int, m.Cols())
 for i := range newRow {
  newRow[i] = value
 }
 m.data = append(m.data, newRow)
}

func (m *Matrix) AddCol(value int) {
 for i := range m.data {
  m.data[i] = append(m.data[i], value)
 }
}

func (m *Matrix) Convolution(core *Matrix) Matrix {
 newRows := m.Rows() - core.Rows() + 1
 newCols := m.Cols() - core.Cols() + 1
 newMatrix := NewMatrix(newRows, newCols, 0)

 for y1 := 0; y1 < newRows; y1++ {
  for x1 := 0; x1 < newCols; x1++ {
   curSum := 0
   for y2 := 0; y2 < core.Rows(); y2++ {
    for x2 := 0; x2 < core.Cols(); x2++ {
     curSum += m.Get(y1+y2, x1+x2) * core.Get(y2, x2)
    }
   }
   newMatrix.Set(y1, x1, curSum)
  }
 }
 return newMatrix
}

func (a *Matrix) Multiplication(b *Matrix) *Matrix {
 newRows, newCols := a.Rows(), b.Cols()
 newMatrix := NewMatrix(newRows, newCols, 0)

 for i := 0; i < newRows; i++ {
  for j := 0; j < newCols; j++ {
   for k := 0; k < b.Rows(); k++ {
    newMatrix.Set(i, j, newMatrix.Get(i, j)+a.Get(i, k)*b.Get(k, j))
   }
  }
 }
 return &newMatrix
}
// Конец вставленного кода

func main() {
    var rowsFirst, colsFirst, firstInitVal,
        rowsCore, colsCore int
    
    fmt.Scan(&rowsFirst, &colsFirst, &firstInitVal)
    first := NewMatrix(rowsFirst, colsFirst, firstInitVal)
    for i := 0; i < first.Rows(); i++ {
        for j := 0; j < first.Cols(); j++ {
            var t int
            fmt.Scan(&t)
            first.Set(i, j, t)
        }
    }

    fmt.Scan(&rowsCore, &colsCore)
    core := NewMatrix(rowsCore, colsCore, 0)
    for i := 0; i < core.Rows(); i++ {
        for j := 0; j < core.Cols(); j++ {
            var t int
            fmt.Scan(&t)
            core.Set(i, j, t)
        }
    }
    
    conv := first.Convolution(&core)
    
    conv.AddRow(1)
    conv.AddCol(1)
    conv.AddCol(1)
    
    mult := conv.Multiplication(&first)
    
    fmt.Print(mult)
}
