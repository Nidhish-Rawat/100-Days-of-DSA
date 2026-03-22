#include <stdio.h>

int main() {
    int arr[100], n, key, i, count = 0, pos = -1;

    printf("enter number of elements: ");
    scanf("%d", &n);

    printf("enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        count++;
        if(arr[i] == key) {
            pos = i + 1;
            break;
        }
    }

    if(pos != -1)
        printf("element found at position %d\n", pos);
    else
        printf("element not found\n");

    printf("number of comparisons: %d\n", count);

    return 0;
}