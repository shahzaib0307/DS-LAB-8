#include <iostream>
#include <string>
using namespace std;

#define SIZE 50

class Stack {
    char items[SIZE];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == SIZE - 1; }
    void push(char ch) {
        if (!isFull()) items[++top] = ch;
    }
    void pop() {
        if (!isEmpty()) top--;
    }
    char peek() {
        if (isEmpty()) return '\0';
        return items[top];
    }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            postfix += c;
        else if (c == '(')
            s.push(c);
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.peek();
                s.pop();
            }
            if (!s.isEmpty() && s.peek() == '(')
                s.pop();
        } 
        else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix += s.peek();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        postfix += s.peek();
        s.pop();
    }
    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;
    return 0;
}

