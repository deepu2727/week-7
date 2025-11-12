// Check if a Queue is Palindrome

#include <stdio.h>
#define MAX 10

int q[MAX], front = 0, rear = -1;

void enqueue(int x){ q[++rear]=x; }
int isPalindrome(){
    int i = front, j = rear;
    while (i < j){
        if (q[i] != q[j]) return 0;
        i++; j--;
    }
    return 1;
}

int main(){
    enqueue(1); enqueue(2); enqueue(3); enqueue(2); enqueue(1);
    if(isPalindrome()) printf("Palindrome Queue\n");
    else printf("Not Palindrome\n");
}
