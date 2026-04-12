#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_list(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;
    int i, value;

    printf("enter %d sorted elements: ", n);

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

struct node* merge(struct node* l1, struct node* l2) {
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;

    printf("merging lists...\n");

    while(l1 != NULL && l2 != NULL) {
        if(l1->data < l2->data) {
            printf("taking %d from list1\n", l1->data);
            tail->next = l1;
            l1 = l1->next;
        } else {
            printf("taking %d from list2\n", l2->data);
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if(l1 != NULL) {
        printf("adding remaining elements of list1\n");
        tail->next = l1;
    }

    if(l2 != NULL) {
        printf("adding remaining elements of list2\n");
        tail->next = l2;
    }

    return dummy.next;
}

void display(struct node* head) {
    printf("merged list: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n1, n2;
    struct node *list1, *list2, *merged;

    printf("enter number of nodes in list1: ");
    scanf("%d", &n1);
    list1 = create_list(n1);

    printf("enter number of nodes in list2: ");
    scanf("%d", &n2);
    list2 = create_list(n2);

    merged = merge(list1, list2);

    display(merged);

    return 0;
}