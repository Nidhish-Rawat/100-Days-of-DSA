#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* build_tree() {
    int value;
    scanf("%d", &value);

    if(value == -1)
        return NULL;

    struct node* root = create_node(value);

    root->left = build_tree();
    root->right = build_tree();

    return root;
}

void zigzag(struct node* root) {
    if(root == NULL)
        return;

    struct node* s1[100];
    struct node* s2[100];
    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    printf("zigzag traversal: ");

    while(top1 != -1 || top2 != -1) {

        while(top1 != -1) {
            struct node* temp = s1[top1--];
            printf("%d ", temp->data);

            if(temp->left != NULL)
                s2[++top2] = temp->left;

            if(temp->right != NULL)
                s2[++top2] = temp->right;
        }

        while(top2 != -1) {
            struct node* temp = s2[top2--];
            printf("%d ", temp->data);

            if(temp->right != NULL)
                s1[++top1] = temp->right;

            if(temp->left != NULL)
                s1[++top1] = temp->left;
        }
    }

    printf("\n");
}

int main() {
    struct node* root;

    printf("enter nodes (-1 for null): ");
    root = build_tree();

    zigzag(root);

    return 0;
}