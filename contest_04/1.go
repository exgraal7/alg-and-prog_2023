package main

import (
    "os"
    "fmt"
    "encoding/json"
)

type task struct {
    UserID int `json:"user_id"`
    Completed bool `json:"completed"`
}

type project struct {
    Tasks      []task `json:"tasks"`
}

func main() {
    var target int
    fmt.Scanln(&target)
    data, _ := os.ReadFile("data.json")
    var parsed []project
    json.Unmarshal(data, &parsed)

    answ := 0
    for _, prj := range(parsed) {
        for _, tsk := range(prj.Tasks) {
            if tsk.UserID == target && tsk.Completed {
                answ++
            }
        }
    }

    fmt.Println(answ)
}
