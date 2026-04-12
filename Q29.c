#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* insert_end(struct node* head, int value) {
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL) {
        printf("node %d created as head\n", value);
        return newnode;
    }

    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    printf("node %d added\n", value);

    return head;
}

void display(struct node* head) {
    printf("list: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int get_length(struct node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct node* rotate_right(struct node* head, int k) {
    if(head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    int len = get_length(head);
    k = k % len;

    if(k == 0) {
        return head;
    }

    struct node *temp = head, *new_tail;
    int steps = len - k - 1;

    while(steps--) {
        temp = temp->next;
    }

    new_tail = temp;
    struct node* new_head = temp->next;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head;
    new_tail->next = NULL;

    printf("list rotated by %d positions\n", k);

    return new_head;
}

int main() {
    int n, i, value, k;
    struct node* head = NULL;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    printf("enter %d elements: ", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert_end(head, value);
    }

    printf("enter k: ");
    scanf("%d", &k);

    display(head);

    head = rotate_right(head, k);

    display(head);

    return 0;
}