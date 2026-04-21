#include <stdio.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST(int graph[MAX][MAX], int n) {
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];
    int totalWeight = 0;

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for (int i = 1; i < n; i++) {
        totalWeight += graph[i][parent[i]];
    }

    return totalWeight;
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int result = primMST(graph, n);

    printf("Total weight of MST: %d\n", result);

    return 0;
}