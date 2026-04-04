#include <stdio.h>

int main() {
    int arr[] = {5, 8, 2, 10, 3};
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
