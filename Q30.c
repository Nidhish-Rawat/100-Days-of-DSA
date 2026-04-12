#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node* next;
};

struct node* insert(struct node* head, int c, int e) {
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff = c;
    newnode->exp = e;
    newnode->next = NULL;

    if(head == NULL) {
        head = newnode;
        printf("term %dx^%d added as head\n", c, e);
        return head;
    }

    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    printf("term %dx^%d added\n", c, e);

    return head;
}

void display(struct node* head) {
    struct node* temp = head;

    printf("polynomial: ");

    while(temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if(temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, i, c, e;
    struct node* poly = NULL;

    printf("enter number of terms: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("enter coefficient and exponent: ");
        scanf("%d %d", &c, &e);
        poly = insert(poly, c, e);
    }

    display(poly);

    return 0;
}