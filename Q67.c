#include <stdio.h>

int stack[100], top = -1;

void push(int x) {
    stack[++top] = x;
}

void DFS(int adj[10][10], int visited[10], int v, int n) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && !visited[i]) {
            DFS(adj, visited, i, n);
        }
    }

    push(v);  // important step
}

int main() {
    int n, adj[10][10], visited[10];

    printf("enter number of vertices: ");
    scanf("%d", &n);

    printf("enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            DFS(adj, visited, i, n);
        }
    }

    printf("topological sort: ");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}