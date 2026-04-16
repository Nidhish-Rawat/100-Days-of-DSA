#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);  // for undirected graph
    newNode->next = adj[v];
    adj[v] = newNode;
}

void printGraph(struct Node* adj[], int V) {
    for(int i = 0; i < V; i++) {
        struct Node* temp = adj[i];
        printf("%d -> ", i);
        while(temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int V = 4;
    struct Node* adj[V];

    for(int i = 0; i < V; i++)
        adj[i] = NULL;

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    printGraph(adj, V);

    return 0;
}