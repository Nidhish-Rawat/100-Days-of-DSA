#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int min_sum = arr[left] + arr[right];
    int l = left, r = right;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            l = left;
            r = right;
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("pair closest to zero is %d and %d\n", arr[l], arr[r]);

    return 0;
}