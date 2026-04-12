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

void right_view(struct node* root) {
    if(root == NULL)
        return;

    struct node* queue[100];
    int front = 0, rear = -1;

    queue[++rear] = root;

    printf("right view: ");

    while(front <= rear) {
        int size = rear - front + 1;

        for(int i = 0; i < size; i++) {
            struct node* temp = queue[front++];

            if(i == size - 1)
                printf("%d ", temp->data);

            if(temp->left != NULL)
                queue[++rear] = temp->left;

            if(temp->right != NULL)
                queue[++rear] = temp->right;
        }
    }

    printf("\n");
}

int main() {
    struct node* root;

    printf("enter nodes (-1 for null): ");
    root = build_tree();

    right_view(root);

    return 0;
}