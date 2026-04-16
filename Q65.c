#include <stdio.h>

int DFS(int adj[10][10], int visited[10], int v, int parent, int n) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1) {
            if(!visited[i]) {
                if(DFS(adj, visited, i, v, n))
                    return 1;
            }
            else if(i != parent) {
                return 1;  // cycle detected
            }
        }
    }
    return 0;
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

    int hasCycle = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(DFS(adj, visited, i, -1, n)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if(hasCycle)
        printf("cycle detected\n");
    else
        printf("no cycle\n");

    return 0;
}