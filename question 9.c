// 9. Implement a Double-Ended Queue (Deque)

#include <stdio.h>
#define MAX 5

int dq[MAX];
int front = -1, rear = -1;

int isFull() { return (front == 0 && rear == MAX-1) || (front == rear+1); }
int isEmpty() { return front == -1; }

void insertFront(int x) {
    if (isFull()) printf("Overflow\n");
    else {
        if (front == -1) front = rear = 0;
        else if (front == 0) front = MAX-1;
        else front--;
        dq[front] = x;
    }
}

void insertRear(int x) {
    if (isFull()) printf("Overflow\n");
    else {
        if (front == -1) front = rear = 0;
        else if (rear == MAX-1) rear = 0;
        else rear++;
        dq[rear] = x;
    }
}

void deleteFront() {
    if (isEmpty()) printf("Underflow\n");
    else {
        if (front == rear) front = rear = -1;
        else if (front == MAX-1) front = 0;
        else front++;
    }
}

void deleteRear() {
    if (isEmpty()) printf("Underflow\n");
    else {
        if (front == rear) front = rear = -1;
        else if (rear == 0) rear = MAX-1;
        else rear--;
    }
}

void display() {
    if (isEmpty()) printf("Deque Empty\n");
    else {
        int i = front;
        printf("Deque: ");
        while (1) {
            printf("%d ", dq[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();
    deleteRear();
    display();
}
