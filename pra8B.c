#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* f = NULL;
struct Node* r = NULL;
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (r == NULL) {
        f = r = newNode;
    } else {
        r->next = newNode;
        r = newNode;
    }
}
void dequeue() {
    if (f == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = f;
    f = f->next;
    if (f == NULL) {
        r = NULL;
    }
    free(temp);
}
void printQueue() {
    if (f == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct Node* temp = f;
        printf("Queue: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
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
