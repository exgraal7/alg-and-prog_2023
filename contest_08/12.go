package main

import (
    "fmt"
)

type Stack interface{
    empty() bool
    push(r rune)
    top() rune
    pop() rune
}

// Начало вставленного кода
type SimpleStack struct {
    items []rune
}

func NewSimpleStack() *SimpleStack {
    return &SimpleStack{}
}

func (s *SimpleStack) empty() bool {
    return len(s.items) == 0
}

func (s *SimpleStack) push(r rune) {
    s.items = append(s.items, r)
}

func (s *SimpleStack) top() rune {
    return s.items[len(s.items)-1]
}

func (s *SimpleStack) pop() rune {
    popped := s.items[len(s.items)-1]
    s.items = s.items[:len(s.items)-1]
    return popped
}
// Конец вставленного кода

func bracketValidator(stack Stack, str string) bool{
    mapping := map[rune]rune{
        ')': '(',
        ']': '[',
        '}': '{',
    }

    for _, char := range str {
        if char == '(' || char == '[' || char == '{' {
            stack.push(char)
        } else if char == ')' || char == ']' || char == '}' {
            if stack.empty() || stack.top() != mapping[char] {
                return false
            }
            stack.pop()
        }
    }

    return stack.empty()
}

func main() {
    var input string
    fmt.Scan(&input)
    fmt.Println(bracketValidator(NewSimpleStack(), input))
}
