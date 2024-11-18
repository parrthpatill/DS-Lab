#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int f = -1, r = -1;

int isFull() {
    return (f == 0 && r == SIZE - 1) || (r == (f - 1) % (SIZE - 1));
}

int isEmpty() {
    return f == -1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue full!\n");
        return;
    }
    if (isEmpty()) {
        f = r = 0;
    } else if (r == SIZE - 1 && f != 0) {
        r = 0;
    } else {
        r++;
    }
    queue[r] = value;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    if (f == r) {
        f = r = -1;
    } else if (f == SIZE - 1) {
        f = 0;
    } else {
        f++;
    }
}

void printQueue() {
    if (isEmpty()) {
        printf("Queue empty!\n");
        return;
    }
    printf("Queue: ");
    if (r >= f) {
        for (int i = f; i <= r; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = f; i < SIZE; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= r; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add\n2. Delete\n3. Print\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to add: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printQueue();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
