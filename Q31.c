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
    printf("%d pushed to stack\n", value);
}

void pop() {
    if(top == -1) {
        printf("stack underflow\n");
        return;
    }
    printf("%d popped from stack\n", stack[top]);
    top--;
}

void peek() {
    if(top == -1) {
        printf("stack is empty\n");
        return;
    }
    printf("top element: %d\n", stack[top]);
}

void display() {
    if(top == -1) {
        printf("stack is empty\n");
        return;
    }

    printf("stack elements: ");
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while(1) {
        printf("\n1 push\n2 pop\n3 peek\n4 display\n5 exit\n");
        printf("enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("exiting...\n");
                return 0;

            default:
                printf("invalid choice\n");
        }
    }

    return 0;
}