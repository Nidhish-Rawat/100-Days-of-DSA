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

    if(m != n) {
        printf("not a symmetric matrix");
        return 0;
    }

    int flag = 1;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j] != A[j][i]) {
                flag = 0;
                break;
            }
        }
    }

    if(flag == 1)
        printf("symmetric matrix");
    else
        printf("not a symmetric matrix");

    return 0;
}