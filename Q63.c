#include <stdio.h>

void DFS(int adj[10][10], int visited[10], int v, int n) {
    printf("%d ", v);
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && !visited[i]) {
            DFS(adj, visited, i, n);
        }
    }
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

    printf("dfs traversal: ");
    DFS(adj, visited, 0, n);

    return 0;
}