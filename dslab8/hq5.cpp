#include <iostream>
using namespace std;

#define SIZE 10

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return front == -1 || front > rear;
    }
    bool isFull() {
        return rear == SIZE - 1;
    }
    void enqueue(int id) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = id;
        cout << "Customer " << id << " added to queue" << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Customer " << arr[front] << " checked out" << endl;
        front++;
    }
    void display() {
        if (isEmpty()) {
            cout << "No customers in queue" << endl;
            return;
        }
        cout << "Current Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int customers[] = {13, 7, 4, 1, 6, 8, 10};
    for (int i = 0; i < 7; i++)
        q.enqueue(customers[i]);

    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}

