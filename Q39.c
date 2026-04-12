#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int value) {
    if(size == MAX) {
        printf("heap overflow\n");
        return;
    }

    int i = size;
    heap[size++] = value;

    while(i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    printf("%d inserted\n", value);
}

void heapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

void delete_min() {
    if(size <= 0) {
        printf("heap underflow\n");
        return;
    }

    printf("%d removed\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;
    heapify(0);
}

void display() {
    if(size == 0) {
        printf("heap is empty\n");
        return;
    }

    printf("heap elements: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while(1) {
        printf("\n1 insert\n2 delete min\n3 display\n4 exit\n");
        printf("enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                delete_min();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("exiting...\n");
                return 0;

            default:
                printf("invalid choice\n");
        }
    }

    return 0;
}