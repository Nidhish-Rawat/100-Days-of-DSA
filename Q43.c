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

struct node* queue[100];
int front = 0, rear = -1;

void enqueue(struct node* temp) {
    queue[++rear] = temp;
}

struct node* dequeue() {
    return queue[front++];
}

struct node* build_tree(int arr[], int n) {
    if(n == 0) return NULL;

    struct node* root = create_node(arr[0]);
    enqueue(root);

    int i = 1;

    while(i < n) {
        struct node* current = dequeue();

        current->left = create_node(arr[i]);
        enqueue(current->left);
        i++;

        if(i < n) {
            current->right = create_node(arr[i]);
            enqueue(current->right);
            i++;
        }
    }

    return root;
}

void level_order(struct node* root) {
    if(root == NULL) return;

    struct node* q[100];
    int f = 0, r = -1;

    q[++r] = root;

    printf("level order traversal: ");

    while(f <= r) {
        struct node* temp = q[f++];
        printf("%d ", temp->data);

        if(temp->left != NULL)
            q[++r] = temp->left;

        if(temp->right != NULL)
            q[++r] = temp->right;
    }

    printf("\n");
}

int main() {
    int n;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct node* root = build_tree(arr, n);

    level_order(root);

    return 0;
}