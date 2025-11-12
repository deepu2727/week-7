// Reverse First K Elements of a Queue
#include <stdio.h>
#define MAX 10

int q[MAX], front = 0, rear = -1, size = 0;

void enqueue(int x) { q[++rear] = x; size++; }
int dequeue() { size--; return q[front++]; }

void reverseK(int k) {
    if (k > size) return;
    int stack[MAX], top = -1;
    for (int i = 0; i < k; i++) stack[++top] = dequeue();
    int temp[MAX], j = 0;
    while (top != -1) temp[j++] = stack[top--];
    while (size--) temp[j++] = dequeue();
    front = 0; rear = -1; size = 0;
    for (int i = 0; i < j; i++) enqueue(temp[i]);
}

void display() {
    printf("Queue: ");
    for (int i = front; i <= rear; i++) printf("%d ", q[i]);
    printf("\n");
}

int main() {
    for (int i = 1; i <= 5; i++) enqueue(i);
    display();
    reverseK(3);
    display();
}
