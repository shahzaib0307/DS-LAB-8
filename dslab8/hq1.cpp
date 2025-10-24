#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

class Stack {
    string items[SIZE];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == SIZE - 1; }
    void push(string item) {
        if (isFull()) {
            cout << "Stack is full" << endl;
            return;
        }
        items[++top] = item;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        top--;
    }
    string peek() {
        if (isEmpty()) return "No item";
        return items[top];
    }
};

int main() {
    Stack todo;
    todo.push("Finish report");
    todo.push("Attend meeting");
    todo.push("Reply to emails");

    if (!todo.isEmpty())
        cout << "Top task: " << todo.peek() << endl;

    todo.pop();

    if (!todo.isEmpty())
        cout << "Next task: " << todo.peek() << endl;
    else
        cout << "No tasks left" << endl;

    return 0;
}

