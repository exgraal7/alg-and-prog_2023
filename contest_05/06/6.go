package main

import (
	"fmt"
	"math/rand"
	"time"
)
type Box struct {
 IsOpened bool
}

type Cat struct {
 IsAlive bool
}

func (b *Box) open() *Cat {
 if !b.IsOpened {
  rand.Seed(time.Now().UnixNano())
  isAlive := rand.Intn(2) == 1 
  cat := &Cat{IsAlive: isAlive}
  b.IsOpened = true
  return cat
 }
 return nil 
}

func (c *Cat) is_alive() bool {
 return c.IsAlive
}

func main(){
    var box Box
cat := box.open()
if cat.is_alive() {
    fmt.Print("alive")
} else {
    fmt.Print("dead")
   }
}
