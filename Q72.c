#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int visited[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        if (visited[str[i]] == 1) {
            printf("First Repeated Character: %c\n", str[i]);
            return 0;
        }
        visited[str[i]] = 1;
    }

    printf("No Repeated Character Found\n");
    return 0;
}