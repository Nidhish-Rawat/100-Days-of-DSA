#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int preIndex = 0;

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

struct node* build(int inorder[], int preorder[], int start, int end) {
    if(start > end)
        return NULL;

    int curr = preorder[preIndex++];
    struct node* root = create_node(curr);

    int pos = search(inorder, start, end, curr);

    root->left = build(inorder, preorder, start, pos - 1);
    root->right = build(inorder, preorder, pos + 1, end);

    return root;
}

void postorder(struct node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int n;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], preorder[n];

    printf("enter inorder: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    printf("enter preorder: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    struct node* root = build(inorder, preorder, 0, n - 1);

    printf("postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}