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

int count_leaf(struct node* root) {
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    return count_leaf(root->left) + count_leaf(root->right);
}

int main() {
    struct node* root;

    printf("enter nodes (-1 for null): ");
    root = build_tree();

    int leaf = count_leaf(root);

    printf("number of leaf nodes: %d\n", leaf);

    return 0;
}