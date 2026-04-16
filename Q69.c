#include <stdio.h>
#define INF 9999

int minDistance(int dist[], int visited[], int n) {
    int min = INF, index;

    for(int i = 0; i < n; i++) {
        if(!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int adj[10][10], int n, int src) {
    int dist[10], visited[10];

    for(int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for(int count = 0; count < n-1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for(int v = 0; v < n; v++) {
            if(!visited[v] && adj[u][v] && 
               dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    printf("shortest distances from source:\n");
    for(int i = 0; i < n; i++) {
        printf("%d -> %d = %d\n", src, i, dist[i]);
    }
}

int main() {
    int n, adj[10][10];

    printf("enter number of vertices: ");
    scanf("%d", &n);

    printf("enter weighted adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    dijkstra(adj, n, 0);

    return 0;
}