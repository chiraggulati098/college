#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int front, rear;
    int array[MAX_SIZE];
};

void initialize(struct CircularQueue* queue) {
    queue->front = queue->rear = -1;
}

int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(struct CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    } else if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->array[queue->rear] = value;
    printf("Enqueued %d to the queue.\n", value);
}

int dequeue(struct CircularQueue* queue) {
    int dequeuedValue;

    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; 
    } else if (queue->front == queue->rear) {
        dequeuedValue = queue->array[queue->front];
        queue->front = queue->rear = -1;
    } else {
        dequeuedValue = queue->array[queue->front];
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    printf("Dequeued %d from the queue.\n", dequeuedValue);
    return dequeuedValue;
}

void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the queue: ");
    int i = queue->front;
    do {
        printf("%d ", queue->array[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);

    printf("\n");
}

int main() {
    struct CircularQueue queue;
    initialize(&queue);

    int choice, value;

    do {
        printf("\nCircular Queue Operations:");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;

            case 2:
                value = dequeue(&queue);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;

            case 3:
                display(&queue);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
