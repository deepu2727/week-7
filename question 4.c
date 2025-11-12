// Check Queue Overflow and Underflow

#include <stdio.h>
#define MAX 3

int q[MAX];
int front = -1, rear = -1;

int isFull() { return rear == MAX - 1; }
int isEmpty() { return front == -1 || front > rear; }

void enqueue(int x) {
    if (isFull()) printf("Queue Overflow\n");
    else {
        if (front == -1) front = 0;
        q[++rear] = x;
    }
}

void dequeue() {
    if (isEmpty()) printf("Queue Underflow\n");
    else printf("Deleted: %d\n", q[front++]);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);  // Overflow
    dequeue();
    dequeue();
    dequeue();
    dequeue();    // Underflow
}
