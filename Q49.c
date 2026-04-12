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
        printf("%d inserted\n", value);
        return create_node(value);
    }

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n, value;
    struct node* root = NULL;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    printf("enter %d values: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("inorder traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}