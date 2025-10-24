
#include <iostream>
#include <string>
using namespace std;

struct Order {
    int id;
    string item;
    int quantity;
};

class Queue {
    int front, rear, size;
    int capacity;
    Order* orders;
public:
    Queue(int cap) {
        capacity = cap;
        front = rear = size = 0;
        orders = new Order[capacity];
    }
    bool isFull() { return size == capacity; }
    bool isEmpty() { return size == 0; }
    void enqueue(int id, string item, int quantity) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        orders[rear].id = id;
        orders[rear].item = item;
        orders[rear].quantity = quantity;
        rear = (rear + 1) % capacity;
        size++;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Processing Order " << orders[front].id << ": " << orders[front].item << " x" << orders[front].quantity << endl;
        front = (front + 1) % capacity;
        size--;
    }
    void displayProcessed() {
        if (isEmpty()) {
            cout << "No processed orders" << endl;
            return;
        }
        cout << "All Processed Orders:" << endl;
        for (int i = 0; i < size; i++) {
            int index = (front + i) % capacity;
            cout << "Order " << orders[index].id << ": " << orders[index].item << " x" << orders[index].quantity << endl;
        }
    }
};

int main() {
    Queue q(5);
    q.enqueue(1, "Burger", 2);
    q.enqueue(2, "Pizza", 1);
    q.enqueue(3, "Pasta", 3);
    q.dequeue();
    q.enqueue(4, "Sandwich", 2);
    q.displayProcessed();
    return 0;
}
