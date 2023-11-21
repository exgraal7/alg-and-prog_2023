package main

import "fmt"

//начало вставленного кода
type Water struct {
    temperature int
}

type Teapot struct {
    water *Water
}

func NewWater(initialTemperature int) *Water {
    return &Water{temperature: initialTemperature}
}

func NewTeapot(water *Water) *Teapot {
    return &Teapot{water: water}
}

func (teapot *Teapot) is_boiling() bool {
    return teapot.water.temperature >= 100
}

func (teapot *Teapot) heat_up(degrees int) {
    teapot.water.temperature += degrees
}
//конец вставленного кода

func main(){
    var temperature, count int
    fmt.Scan(&temperature, &count)

    heat := NewQueue()
    for i := 0; i < count; i++ {
        var t int
        fmt.Scan(&t)
        heat.Push(t)
    }

    water := NewWater(temperature)
    teapot := NewTeapot(water)
    
    for !teapot.is_boiling() {
        teapot.heat_up(heat.Pop())
    }
    
    for !heat.IsEmpty() {
        fmt.Print(heat.Pop(), " ")
    }
}
