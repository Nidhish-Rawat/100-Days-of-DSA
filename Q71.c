#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void init() {
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);

    int i = 1;
    while(hashTable[index] != -1) {
        index = (hashFunction(key) + i * i) % SIZE;
        i++;
        if(i == SIZE) {
            printf("Hash Table Full\n");
            return;
        }
    }

    hashTable[index] = key;
}

void display() {
    for(int i = 0; i < SIZE; i++) {
        printf("%d -> %d\n", i, hashTable[i]);
    }
}

int main() {
    init();

    insert(23);
    insert(43);
    insert(13);

    display();

    return 0;
}