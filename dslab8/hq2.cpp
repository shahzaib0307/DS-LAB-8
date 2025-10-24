#include <iostream>
#include <string>
using namespace std;

struct Node {
    string url;
    Node* next;
};

class Stack {
    string data[100];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    void push(string val) { data[++top] = val; }
    void pop() { if (!isEmpty()) top--; }
    string peek() { return isEmpty() ? "" : data[top]; }
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = NULL; }
    void addFront(string url) {
        Node* n = new Node;
        n->url = url;
        n->next = head;
        head = n;
    }
    void removeFront() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void showCurrent() {
        if (head) cout << "Current page: " << head->url << endl;
        else cout << "No pages open" << endl;
    }
};

void simulateBack(LinkedList& history, Stack& st, int times) {
    for (int i = 0; i < times; i++) {
        if (!st.isEmpty()) {
            st.pop();
            history.removeFront();
        }
    }
    history.showCurrent();
}

int main() {
    LinkedList history;
    Stack st;

    history.addFront("Instagram");
    st.push("Instagram");
    history.addFront("LinkedIn");
    st.push("LinkedIn");
    history.addFront("Twitter");
    st.push("Twitter");
    history.addFront("Facebook");
    st.push("Facebook");
    history.addFront("Google");
    st.push("Google");

    cout << "Before going back: ";
    history.showCurrent();

    simulateBack(history, st, 2);

    return 0;
}

