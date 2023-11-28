#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
int circularQueue[MAX_SIZE];
int front = 0, rear = 0;

void dispQ() {
    if (front == rear) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue:\t";
    int i = front;
    bool firstElement = true;

    do {
        if (firstElement) {
            cout << circularQueue[i];
            firstElement = false;
        } else {
            cout << "\t" << circularQueue[i];
        }
        i = (i + 1) % MAX_SIZE;
    } while (i != rear);

    cout << endl;
}

void enqueue(int value) {
    if ((rear + 1) % MAX_SIZE == front) {
        cout << "Circular Queue Overflow!\n";
    } else {
        circularQueue[rear] = value;
        rear = (rear + 1) % MAX_SIZE;
    }
}

void dequeue() {
    if (front == rear) {
        cout << "Circular Queue Underflow!\n";
    } else {
        cout << circularQueue[front] << " dequeued from the queue." << endl;
        front = (front + 1) % MAX_SIZE;
    }
}

int main() {
    int choice;
    bool status = true;

    dispQ();

    while (status) {
        cout << "1. Enqueue\t2. Dequeue\t0. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 0:
                dispQ();
                status = false;
                break;
            case 1: {
                int value;
                cout << "Enter data to enqueue: ";
                cin >> value;
                enqueue(value);
                dispQ();
                break;
            }
            case 2:
                dequeue();
                dispQ();
                break;
        }
    }

    return 0;
}
