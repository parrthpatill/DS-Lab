#include <stdio.h>
#define MAX 5

int queue[MAX];
int f = -1, r = -1;

void enqueue(int value) {
    if (r == MAX - 1) {
        printf("Queue full.\n");
    } else {
        if (f == -1) f = 0;
        queue[++r] = value;
        printf("Added %d to the queue.\n", value);
    }
}

void dequeue() {
    if (f == -1 || f > r) {
        printf("Queue empty.\n");
    } else {
        printf("Deleted %d from the queue.\n", queue[f]);
        f++;
        if (f > r) {
            f = r = -1;
        }
    }
}

void printQueue() {
    if (f == -1) {
        printf("Queue empty.\n");
    } else {
        printf("Queue: ");
        for (int i = f; i <= r; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    char cont;

    while (1) {
        printf("\n1. Add\n2. Delete\n3. Print\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("Enter value to add: ");
                    scanf("%d", &value);
                    enqueue(value);
                    printf("Add another? (y/n): ");
                    scanf(" %c", &cont);
                } while (cont == 'y' || cont == 'Y');
                break;

            case 2:
                do {
                    dequeue();
                    printf("Delete another? (y/n): ");
                    scanf(" %c", &cont);
                } while (cont == 'y' || cont == 'Y');
                break;

            case 3:
                printQueue();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
