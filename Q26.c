#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* insert_end(struct node* head, int value) {
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(head == NULL) {
        head = newnode;
        printf("node %d created as head\n", value);
        return head;
    }

    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;

    printf("node %d inserted at end\n", value);

    return head;
}

void traverse_forward(struct node* head) {
    struct node* temp = head;
    printf("forward traversal: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void traverse_backward(struct node* head) {
    struct node* temp = head;

    if(head == NULL) {
        return;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }

    printf("backward traversal: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int n, i, value;
    struct node* head = NULL;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    printf("enter %d elements: ", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert_end(head, value);
    }

    traverse_forward(head);
    traverse_backward(head);

    return 0;
}