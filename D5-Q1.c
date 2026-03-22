#include <stdio.h>

int main() {
    int a[100], b[100], c[200];
    int p, q, i = 0, j = 0, k = 0;

    printf("enter the number of elements in the first array: ");
    scanf("%d", &p);
    for(int x = 0; x < p; x++) {
        scanf("%d", &a[x]);
    }

    printf("enter the number of elements in the second array: ");
    scanf("%d", &q);
    for(int x = 0; x < q; x++) {
        scanf("%d", &b[x]);
    }

    while(i < p && j < q) {
        if(a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while(i < p) {
        c[k++] = a[i++];
    }

    while(j < q) {
        c[k++] = b[j++];
    }

    for(int x = 0; x < k; x++) {
        printf("%d ", c[x]);
    }

    return 0;
}

