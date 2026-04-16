#include <stdio.h>

int DFS(int adj[10][10], int visited[10], int recStack[10], int v, int n) {
    visited[v] = 1;
    recStack[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1) {
            if(!visited[i]) {
                if(DFS(adj, visited, recStack, i, n))
                    return 1;
            }
            else if(recStack[i]) {
                return 1;  // cycle detected
            }
        }
    }

    recStack[v] = 0;  // backtrack
    return 0;
}

int main() {
    int n, adj[10][10], visited[10], recStack[10];

    printf("enter number of vertices: ");
    scanf("%d", &n);

    printf("enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    int hasCycle = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(DFS(adj, visited, recStack, i, n)) {
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