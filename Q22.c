#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n, i, value, count = 0;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    printf("enter %d elements: ", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
            printf("node %d created as head\n", value);
        } else {
            temp->next = newnode;
            temp = newnode;
            printf("node %d added to list\n", value);
        }
    }

    printf("traversing the linked list...\n");

    temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("total number of nodes: %d\n", count);

    return 0;
}