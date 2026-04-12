#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("%d enqueued\n", value);
}

void dequeue() {
    if(front == NULL) {
        printf("queue underflow\n");
        return;
    }

    struct node* temp = front;
    printf("%d dequeued\n", front->data);

    front = front->next;

    if(front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {
    if(front == NULL) {
        printf("queue is empty\n");
        return;
    }

    struct node* temp = front;

    printf("queue elements: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
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