// Implement a Priority Queue

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data, priority;
    struct Node *next;
};
struct Node *front = NULL;

void enqueue(int d, int p) {
    struct Node *n = malloc(sizeof(struct Node)), *t;
    n->data = d; n->priority = p; n->next = NULL;
    if (!front || p < front->priority) {
        n->next = front;
        front = n;
    } else {
        t = front;
        while (t->next && t->next->priority <= p)
            t = t->next;
        n->next = t->next;
        t->next = n;
    }
}

void dequeue() {
    if (!front) printf("Underflow\n");
    else {
        printf("Deleted: %d\n", front->data);
        struct Node *t = front;
        front = front->next;
        free(t);
    }
}

void display() {
    struct Node *t = front;
    while (t) {
        printf("(%d,p%d) ", t->data, t->priority);
        t = t->next;
    }
    printf("\n");
}

int main() {
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);
    display();
    dequeue();
    display();
}
