#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int stack[MAX];
int top = -1;

void enqueue(int value) {
    if(rear == MAX - 1) {
        printf("queue overflow\n");
        return;
    }
    if(front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if(front == -1 || front > rear) {
        printf("queue underflow\n");
        return -1;
    }
    return queue[front++];
}

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

void display() {
    if(front == -1 || front > rear) {
        printf("queue is empty\n");
        return;
    }
    printf("queue: ");
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int n, value;

    printf("enter number of elements: ");
    scanf("%d", &n);

    printf("enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    display();

    while(front <= rear) {
        push(dequeue());
    }

    front = 0;
    rear = -1;

    while(top != -1) {
        enqueue(pop());
    }

    printf("reversed ");
    display();

    return 0;
}