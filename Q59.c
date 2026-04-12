#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int postIndex;

struct node* create_node(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int search(int inorder[], int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

struct node* build(int inorder[], int postorder[], int start, int end) {
    if(start > end)
        return NULL;

    int curr = postorder[postIndex--];
    struct node* root = create_node(curr);

    int pos = search(inorder, start, end, curr);

    root->right = build(inorder, postorder, pos + 1, end);
    root->left = build(inorder, postorder, start, pos - 1);

    return root;
}

void preorder(struct node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    int n;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("enter inorder: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    printf("enter postorder: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    postIndex = n - 1;

    struct node* root = build(inorder, postorder, 0, n - 1);

    printf("preorder traversal: ");
    preorder(root);
    printf("\n");

    return 0;
}