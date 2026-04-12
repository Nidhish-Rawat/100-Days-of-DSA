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

int search(struct node* root, int key) {
    if(root == NULL)
        return 0;

    if(root->data == key)
        return 1;

    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    int n, value, key;
    struct node* root = NULL;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    printf("enter %d values: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("enter value to search: ");
    scanf("%d", &key);

    if(search(root, key))
        printf("value found\n");
    else
        printf("value not found\n");

    return 0;
}