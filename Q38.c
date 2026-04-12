#include <stdio.h>

#define MAX 5

int dq[MAX];
int front = -1, rear = -1;

void insert_front(int value) {
    if((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("deque overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    } else if(front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    dq[front] = value;
    printf("%d inserted at front\n", value);
}

void insert_rear(int value) {
    if((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("deque overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    } else if(rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    dq[rear] = value;
    printf("%d inserted at rear\n", value);
}

void delete_front() {
    if(front == -1) {
        printf("deque underflow\n");
        return;
    }

    printf("%d deleted from front\n", dq[front]);

    if(front == rear) {
        front = rear = -1;
    } else if(front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void delete_rear() {
    if(front == -1) {
        printf("deque underflow\n");
        return;
    }

    printf("%d deleted from rear\n", dq[rear]);

    if(front == rear) {
        front = rear = -1;
    } else if(rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void display() {
    if(front == -1) {
        printf("deque is empty\n");
        return;
    }

    printf("deque elements: ");
    int i = front;

    while(1) {
        printf("%d ", dq[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int choice, value;

    while(1) {
        printf("\n1 insert front\n2 insert rear\n3 delete front\n4 delete rear\n5 display\n6 exit\n");
        printf("enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("enter value: ");
                scanf("%d", &value);
                insert_front(value);
                break;

            case 2:
                printf("enter value: ");
                scanf("%d", &value);
                insert_rear(value);
                break;

            case 3:
                delete_front();
                break;

            case 4:
                delete_rear();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("exiting...\n");
                return 0;

            default:
                printf("invalid choice\n");
        }
    }

    return 0;
}