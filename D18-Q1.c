#include <stdio.h>

void rotate(int arr[], int n, int k) {
    int temp[k];

    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }

    for (int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }

    for (int i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    rotate(arr, n, k);

    printf("array after rotation:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}