#include <stdio.h>

int isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (arr[i] > arr[2*i + 1])
            return 0;
        if (2*i + 2 < n && arr[i] > arr[2*i + 2])
            return 0;
    }
    return 1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isMinHeap(arr, n))
        printf("valid min heap");
    else
        printf("not a min heap");

    return 0;
}