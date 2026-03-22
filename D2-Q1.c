#include <stdio.h>

int main() {
    int arr[100], n, pos;

    printf("enter number of elements: ");
    scanf("%d", &n);

    printf("enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("enter position to delete: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n) {
        printf("invalid position\n");
        return 0;
    }

    for(int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    printf("array after deletion:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}