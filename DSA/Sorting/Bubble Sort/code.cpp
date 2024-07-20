#include <stdio.h>

#define MAX_SIZE 5  // Maximum size of the queue

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to enqueue (insert) an element
void enqueue(int data) {
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }

    if (front == -1) {  // First element
        front = 0;
    }

    rear = (rear + 1) % MAX_SIZE;  // Circular increment
    queue[rear] = data;
}

// Function to dequeue (remove) an element
int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }

    int data = queue[front];

    if (front == rear) {  // Reset queue if only one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }

    return data;
}

// Function to display the queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i != rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[rear]);
}

int main() {
    int choice, data;

    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data != -1) {
                    printf("Dequeued: %d\n", data);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}