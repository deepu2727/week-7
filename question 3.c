// Insert and Delete Elements and Display after Each Operation

#include <stdio.h>
#define MAX 5

int q[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) printf("Overflow\n");
    else {
        if (front == -1) front = 0;
        q[++rear] = x;
        printf("Inserted %d\n", x);
        display();
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Underflow\n");
    else {
        printf("Deleted %d\n", q[front++]);
        display();
    }
}

void display() {
    if (front == -1 || front > rear)
        printf("Queue Empty\n");
    else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    dequeue();
    enqueue(3);
    display();
}
