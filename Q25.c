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

int count_occurrence(struct node* head, int key) {
    int count = 0;
    struct node* temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}

void display(struct node* head) {
    printf("linked list: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, key, result;
    struct node *head;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    head = create_list(n);

    printf("enter element to count: ");
    scanf("%d", &key);

    display(head);

    result = count_occurrence(head, key);

    printf("occurrences of %d: %d\n", key, result);

    return 0;
}