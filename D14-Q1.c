#include <stdio.h>

int main() {
    int n;

    printf("enter size of matrix: ");
    scanf("%d", &n);

    int A[n][n];

    printf("enter matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int flag = 1;

    for(int i = 0; i < n && flag == 1; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j && A[i][j] != 1) {
                flag = 0;
                break;
            }
            if(i != j && A[i][j] != 0) {
                flag = 0;
                break;
            }
        }
    }

    if(flag == 1)
        printf("identity matrix");
    else
        printf("not an identity matrix");

    return 0;
}