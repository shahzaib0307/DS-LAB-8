#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

class Stack {
public:
    Node* top;
    Stack() { top = NULL; }
    bool isEmpty() { return top == NULL; }
    void push(string val) {
        Node* n = new Node;
        n->data = val;
        n->next = top;
        top = n;
    }
    void pop() {
        if (isEmpty()) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    string peek() {
        if (isEmpty()) return "";
        return top->data;
    }
    void display() {
        Node* temp = top;
        cout << "Stack (Top to Bottom): ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push("x");
    s.push("=");
    s.push("12");
    s.push("+");
    s.push("13");
    s.push("-");
    s.push("5");
    s.push("(");
    s.push("0.5");
    s.push("+");
    s.push("0.5");
    s.push(")");
    s.push("+");
    s.push("1");

    double result = 12 + 13 - 5 * (0.5 + 0.5) + 1;
    s.push(to_string((int)result));

    s.display();
    return 0;
}

