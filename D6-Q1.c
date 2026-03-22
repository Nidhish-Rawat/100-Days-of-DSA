#include <stdio.h>

int main() {
    int arr[100], n, i, j;

    printf("enter the number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if(n == 0) return 0;

    j = 0;

    for(i = 1; i < n; i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    for(i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}