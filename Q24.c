#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_list(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;
    int i, value;

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
            printf("node %d added\n", value);
        }
    }
    return head;
}

struct node* delete_key(struct node* head, int key) {
    struct node *temp = head, *prev = NULL;

    if(head == NULL) {
        printf("list is empty\n");
        return head;
    }

    if(temp->data == key) {
        printf("deleting node %d (head)\n", key);
        head = temp->next;
        free(temp);
        return head;
    }

    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("key %d not found\n", key);
        return head;
    }

    printf("deleting node %d\n", key);
    prev->next = temp->next;
    free(temp);

    return head;
}

void display(struct node* head) {
    printf("current list: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, key;
    struct node *head;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    head = create_list(n);

    printf("enter key to delete: ");
    scanf("%d", &key);

    head = delete_key(head, key);

    display(head);

    return 0;
}