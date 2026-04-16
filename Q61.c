#include <stdio.h>

int main() {
    int n, i, j;

    printf("enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    printf("enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("adjacency matrix is:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}