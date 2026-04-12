#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if(top == MAX - 1) {
        printf("stack overflow\n");
        return;
    }
    top++;
    stack[top] = value;
    printf("%d pushed\n", value);
}

void pop() {
    if(top == -1) {
        printf("stack underflow\n");
        return;
    }
    printf("%d popped\n", stack[top]);
    top--;
}

int main() {
    int n, i, value;

    printf("enter number of elements to push: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    printf("performing pop operation\n");
    pop();

    return 0;
}