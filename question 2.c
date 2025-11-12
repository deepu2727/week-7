// Implement a Queue using a Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    if (rear == NULL)
        front = rear = n;
    else {
        rear->next = n;
        rear = n;
    }
}

void dequeue() {
    if (front == NULL)
        printf("Queue Underflow\n");
    else {
        struct Node *temp = front;
        printf("Deleted: %d\n", temp->data);
        front = front->next;
        if (front == NULL) rear = NULL;
        free(temp);
    }
}

void display() {
    struct Node *t = front;
    if (!t) printf("Queue is Empty\n");
    else {
        printf("Queue: ");
        while (t) { printf("%d ", t->data); t = t->next; }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
}
