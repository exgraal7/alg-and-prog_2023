#include <iostream>
#include <stack>
#include <string>


int getPriority(char op){
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '^')
        return 3;
    else
        return 0;
}

std::string infixToPostfix(const std::string& expression){
    std::string postfix;
    std::stack<char> operatorStack;
    bool Previsdigit = false;
    for (char ch : expression){    
        if (std::isdigit(ch)){
            if (Previsdigit){
                postfix += ch;
            }
            else{
                postfix += ' ';
                postfix += ch;
            }
            Previsdigit = true;
        }
        else{
            Previsdigit = false;

            if (ch == '('){
                operatorStack.push(ch);
            }
            else if (ch == ')'){
                while (!operatorStack.empty() && operatorStack.top() != '(') {
                        postfix += ' ';
                        postfix += operatorStack.top();
                        operatorStack.pop();
                }
                operatorStack.pop();
            }

            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%'){
                if(ch == '^'){
                    while (!operatorStack.empty() && getPriority(operatorStack.top()) > getPriority(ch)) {
                        postfix += ' ';
                        postfix += operatorStack.top();
                        operatorStack.pop();
                    }
                    operatorStack.push(ch);
                }
                else{
                    while (!operatorStack.empty() && getPriority(operatorStack.top()) >= getPriority(ch)) {
                        postfix += ' ';
                        postfix += operatorStack.top();
                        operatorStack.pop();
                    }
                    operatorStack.push(ch);
                }
            }
        }
    }
    
    while (!operatorStack.empty()){
        postfix += ' ';
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    postfix.erase(postfix.begin());

    return postfix;
}

int main(){
    std::string expression;
    std::getline(std::cin, expression);

    std::string postfix = infixToPostfix(expression);
    
    if (!postfix.empty()) {
        std::cout << postfix;
    }
}