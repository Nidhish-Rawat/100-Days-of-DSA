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

struct node* lca(struct node* root, int n1, int n2) {
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    struct node* left = lca(root->left, n1, n2);
    struct node* right = lca(root->right, n1, n2);

    if(left != NULL && right != NULL)
        return root;

    if(left != NULL)
        return left;
    else
        return right;
}

int main() {
    struct node* root;
    int n1, n2;

    printf("enter nodes (-1 for null): ");
    root = build_tree();

    printf("enter two values: ");
    scanf("%d %d", &n1, &n2);

    struct node* result = lca(root, n1, n2);

    if(result != NULL)
        printf("lca: %d\n", result->data);
    else
        printf("lca not found\n");

    return 0;
}