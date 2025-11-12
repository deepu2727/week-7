// Implement a Circular Queue using Array
#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

int isFull() { return (rear + 1) % MAX == front; }
int isEmpty() { return front == -1; }

void enqueue(int x) {
    if (isFull()) printf("Queue Overflow\n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        cq[rear] = x;
    }
}

void dequeue() {
    if (isEmpty()) printf("Queue Underflow\n");
    else {
        printf("Deleted: %d\n", cq[front]);
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) printf("Queue Empty\n");
    else {
        printf("Circular Queue: ");
        int i = front;
        while (1) {
            printf("%d ", cq[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    enqueue(40);
    enqueue(50);
    display();
}
