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

int is_mirror(struct node* t1, struct node* t2) {
    if(t1 == NULL && t2 == NULL)
        return 1;

    if(t1 == NULL || t2 == NULL)
        return 0;

    if(t1->data != t2->data)
        return 0;

    return is_mirror(t1->left, t2->right) &&
           is_mirror(t1->right, t2->left);
}

int main() {
    struct node* root;

    printf("enter nodes (-1 for null): ");
    root = build_tree();

    if(is_mirror(root, root))
        printf("tree is symmetric\n");
    else
        printf("tree is not symmetric\n");

    return 0;
}