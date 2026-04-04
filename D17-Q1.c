#include <stdio.h>

int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    printf("maximum element is %d\n", max);
    printf("minimum element is %d\n", min);

    return 0;
}