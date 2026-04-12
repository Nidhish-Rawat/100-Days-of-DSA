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

struct node* insert(struct node* root, int value) {
    if(root == NULL) {
        return create_node(value);
    }

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct node* lca(struct node* root, int n1, int n2) {
    if(root == NULL)
        return NULL;

    if(n1 < root->data && n2 < root->data)
        return lca(root->left, n1, n2);

    if(n1 > root->data && n2 > root->data)
        return lca(root->right, n1, n2);

    return root;
}

int main() {
    int n, value, n1, n2;
    struct node* root = NULL;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    printf("enter %d values: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("enter two values: ");
    scanf("%d %d", &n1, &n2);

    struct node* result = lca(root, n1, n2);

    if(result != NULL)
        printf("lca: %d\n", result->data);
    else
        printf("lca not found\n");

    return 0;
}