#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = -1;

void enqueue(int value) {
    if(size == MAX - 1) {
        printf("queue overflow\n");
        return;
    }

    size++;
    pq[size] = value;

    for(int i = size; i > 0; i--) {
        if(pq[i] > pq[i - 1]) {
            int temp = pq[i];
            pq[i] = pq[i - 1];
            pq[i - 1] = temp;
        }
    }

    printf("%d inserted\n", value);
}

void dequeue() {
    if(size == -1) {
        printf("queue underflow\n");
        return;
    }

    printf("%d removed\n", pq[0]);

    for(int i = 0; i < size; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

void display() {
    if(size == -1) {
        printf("queue is empty\n");
        return;
    }

    printf("priority queue: ");
    for(int i = 0; i <= size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while(1) {
        printf("\n1 insert\n2 delete\n3 display\n4 exit\n");
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