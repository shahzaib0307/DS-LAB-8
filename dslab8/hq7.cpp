#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

class Queue {
    string patrons[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isFull() {
        return rear == SIZE - 1;
    }
    bool isEmpty() {
        return front == -1 || front > rear;
    }
    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full. Please wait." << endl;
            return;
        }
        if (front == -1) front = 0;
        patrons[++rear] = name;
        cout << name << " added to the queue." << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "No patrons to service." << endl;
            return;
        }
        cout << patrons[front] << "'s book transaction completed." << endl;
        front++;
    }
    void display() {
        if (isEmpty()) {
            cout << "No patrons in the queue." << endl;
            return;
        }
        cout << "Current queue of patrons: ";
        for (int i = front; i <= rear; i++)
            cout << patrons[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue libraryQueue;
    int choice;
    string name;

    while (true) {
        cout << "\n--- Library Transaction Queue ---" << endl;
        cout << "1. Add Patron to Queue" << endl;
        cout << "2. Complete Patron Transaction" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Patron Name: ";
            cin >> name;
            libraryQueue.enqueue(name);
            break;
        case 2:
            libraryQueue.dequeue();
            break;
        case 3:
            libraryQueue.display();
            break;
        case 4:
            cout << "Exiting system." << endl;
            return 0;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}

