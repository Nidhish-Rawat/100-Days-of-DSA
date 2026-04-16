#include <stdio.h>

int queue[100], front = -1, rear = -1;

void enqueue(int x) {
    if(rear == 99) return;
    if(front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void BFS(int adj[10][10], int visited[10], int start, int n) {
    enqueue(start);
    visited[start] = 1;

    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
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

    printf("bfs traversal: ");
    BFS(adj, visited, 0, n);

    return 0;
}