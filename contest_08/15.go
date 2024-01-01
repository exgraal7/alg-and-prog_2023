package main

import (
    "fmt"
)

// Начало вставленного кода
import (
 "strings"
)
type BinaryTreeNode struct {
 value       int
 left, right *BinaryTreeNode
}

func NewBinaryTreeNode(value int) *BinaryTreeNode {
 return &BinaryTreeNode{value: value}
}

func (t *BinaryTreeNode) insertNode(value int) {
 if value < t.value {
  if t.left == nil {
   t.left = NewBinaryTreeNode(value)
  } else {
   t.left.insertNode(value)
  }
 } else if value > t.value {
  if t.right == nil {
   t.right = NewBinaryTreeNode(value)
  } else {
   t.right.insertNode(value)
  }
 }
}

func (t *BinaryTreeNode) findNode(value int) *BinaryTreeNode {
 if t == nil || t.value == value {
  return t
 }

 if value < t.value {
  return t.left.findNode(value)
 }
 return t.right.findNode(value)
}

func (t *BinaryTreeNode) removeNode(value int) *BinaryTreeNode {
 if t == nil {
  return nil
 }

 if value < t.value {
  t.left = t.left.removeNode(value)
 } else if value > t.value {
  t.right = t.right.removeNode(value)
 } else {
  if t.left == nil {
   return t.right
  } else if t.right == nil {
   return t.left
  }

  t.value = t.left.findMax().value
  t.left = t.left.removeNode(t.value)
 }

 return t
}

func (t *BinaryTreeNode) findMax() *BinaryTreeNode {
 for t.right != nil {
  t = t.right
 }
 return t
}

func (t *BinaryTreeNode) String() string {
 var result []string
 queue := []*BinaryTreeNode{t}

 for len(queue) > 0 {
  node := queue[0]
  queue = queue[1:]

  if node != nil {
   result = append(result, fmt.Sprint(node.value))
   queue = append(queue, node.left, node.right)
  }
 }

 return strings.Join(result, " ")
}
// Конец вставленного кода

func main() {
    var count int
    fmt.Scan(&count)
    
    var root *BinaryTreeNode
    for count > 0 {
        var command string
        var value int
        fmt.Scan(&command, &value)
        
        if command == "insert" {
            if root == nil {
                root = NewBinaryTreeNode(value)
            }
            root.insertNode(value)
        }else if command == "remove" {
            root = root.removeNode(value)
        }else if command == "find" {
            fmt.Println(root.findNode(value))
        }
        
        count--
    }
}
