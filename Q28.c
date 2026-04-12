#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* new_node(int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    printf("node %d created\n", value);
    return temp;
}

int get_length(struct node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct node* find_intersection(struct node* h1, struct node* h2) {
    int l1 = get_length(h1);
    int l2 = get_length(h2);

    printf("length of list1: %d\n", l1);
    printf("length of list2: %d\n", l2);

    int diff;
    struct node *p1 = h1, *p2 = h2;

    if(l1 > l2) {
        diff = l1 - l2;
        printf("aligning list1 by %d steps\n", diff);
        while(diff--) p1 = p1->next;
    } else {
        diff = l2 - l1;
        printf("aligning list2 by %d steps\n", diff);
        while(diff--) p2 = p2->next;
    }

    printf("searching for intersection...\n");

    while(p1 != NULL && p2 != NULL) {
        if(p1 == p2) {
            return p1;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}

void display(struct node* head) {
    printf("list: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head1, *head2, *common;

    printf("creating list1...\n");
    head1 = new_node(10);
    head1->next = new_node(20);
    head1->next->next = new_node(30);
    head1->next->next->next = new_node(40);

    printf("creating list2...\n");
    head2 = new_node(5);
    head2->next = new_node(15);

    printf("creating intersection...\n");
    common = head1->next->next;
    head2->next->next = common;

    display(head1);
    display(head2);

    struct node* result = find_intersection(head1, head2);

    if(result != NULL) {
        printf("intersection point found: %d\n", result->data);
    } else {
        printf("no intersection\n");
    }

    return 0;
}