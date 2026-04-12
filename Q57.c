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

void mirror(struct node* root) {
    if(root == NULL)
        return;

    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root;

    printf("enter nodes (-1 for null): ");
    root = build_tree();

    printf("inorder before mirror: ");
    inorder(root);
    printf("\n");

    mirror(root);

    printf("inorder after mirror: ");
    inorder(root);
    printf("\n");

    return 0;
}