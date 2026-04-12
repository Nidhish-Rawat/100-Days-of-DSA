#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if((rear + 1) % MAX == front) {
        printf("queue overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("%d enqueued\n", value);
}

void dequeue() {
    if(front == -1) {
        printf("queue underflow\n");
        return;
    }

    printf("%d dequeued\n", queue[front]);

    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if(front == -1) {
        printf("queue is empty\n");
        return;
    }

    printf("queue elements: ");
    int i = front;

    while(1) {
        printf("%d ", queue[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int choice, value;

    while(1) {
        printf("\n1 enqueue\n2 dequeue\n3 display\n4 exit\n");
        printf("enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("exiting...\n");
                return 0;

            default:
                printf("invalid choice\n");
        }
    }

    return 0;
}