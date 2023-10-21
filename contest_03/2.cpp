#include <iostream>
#include <stack>
using namespace std;

bool areBracketsBalanced(string expression) {
    stack<char> s;
    for (char bracket : expression) {
        if (bracket == '(' || bracket == '{' || bracket == '[') {
            s.push(bracket);
        } else if (bracket == ')' || bracket == '}' || bracket == ']') {
            if (s.empty()) {
                return false; 
            }
            char top = s.top();
            s.pop();
            if ((bracket == ')' && top != '(') ||
                (bracket == '}' && top != '{') ||
                (bracket == ']' && top != '[')) {
                return false; 
            }
        }
    }
    return s.empty(); 
}

int main() {
    string text;
    getline(cin, text, '!');
    if (areBracketsBalanced(text)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}