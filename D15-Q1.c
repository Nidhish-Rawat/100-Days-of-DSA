#include <stdio.h>

int main() {
    int m, n;

    printf("enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int A[m][n];

    printf("enter matrix:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int sum = 0;

    for(int i = 0; i < m && i < n; i++) {
        sum += A[i][i];
    }

    printf("sum of primary diagonal: %d", sum);

    return 0;
}