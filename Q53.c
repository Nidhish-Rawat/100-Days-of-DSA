#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct pair {
    struct node* node;
    int hd;
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

void vertical_order(struct node* root) {
    if(root == NULL)
        return;

    struct pair queue[100];
    int front = 0, rear = -1;

    int map[200][200] = {0};
    int count[200] = {0};

    int offset = 100;

    queue[++rear].node = root;
    queue[rear].hd = 0;

    while(front <= rear) {
        struct pair temp = queue[front++];

        int hd = temp.hd + offset;

        map[hd][count[hd]++] = temp.node->data;

        if(temp.node->left != NULL) {
            queue[++rear].node = temp.node->left;
            queue[rear].hd = temp.hd - 1;
        }

        if(temp.node->right != NULL) {
            queue[++rear].node = temp.node->right;
            queue[rear].hd = temp.hd + 1;
        }
    }

    printf("vertical order:\n");

    for(int i = 0; i < 200; i++) {
        if(count[i] != 0) {
            for(int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    struct node* root;

    printf("enter nodes (-1 for null): ");
    root = build_tree();

    vertical_order(root);

    return 0;
}