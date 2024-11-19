#include <stdio.h>

#define SIZE 10
#define EMPTY -1

int table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = EMPTY;
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int idx = hash(key);
    while (table[idx] != EMPTY) {
        idx = (idx + 1) % SIZE;
    }
    table[idx] = key;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == EMPTY)
            printf("Index %d: EMPTY\n", i);
        else
            printf("Index %d: %d\n", i, table[i]);
    }
}

int main() {
    int ch, key;
    init();

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                printf("Key %d inserted.\n", key);
                break;
            case 2:
                printf("Hash Table:\n");
                display();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
