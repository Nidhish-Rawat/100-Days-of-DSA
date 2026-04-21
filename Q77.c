#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], queue[MAX];

void dfs(int v, int n) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

void bfs(int start, int n) {
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int isConnected(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            return 0;
    }
    return 1;
}

int main() {
    int n, choice;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("1. DFS\n2. BFS\nEnter choice: ");
    scanf("%d", &choice);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    if (choice == 1)
        dfs(0, n);
    else if (choice == 2)
        bfs(0, n);
    else {
        printf("Invalid choice\n");
        return 0;
    }

    if (isConnected(n))
        printf("Graph is Connected\n");
    else
        printf("Graph is Not Connected\n");

    return 0;
}