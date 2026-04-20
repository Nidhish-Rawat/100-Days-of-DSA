#include <stdio.h>

int maxLen(int arr[], int n) {
    int max_length = 0;
    int sum = 0;

    int hash[10000];
    for (int i = 0; i < 10000; i++) hash[i] = -2;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            max_length = i + 1;
        }

        if (hash[sum + 5000] != -2) {
            int length = i - hash[sum + 5000];
            if (length > max_length)
                max_length = length;
        } else {
            hash[sum + 5000] = i;
        }
    }

    return max_length;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", maxLen(arr, n));
    return 0;
}