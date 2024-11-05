#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

void create(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void create_nodes() {
    int value;
    char choice;
    do {
        printf("Enter value to insert: ");
        scanf("%d", &value);
        create(value);
        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

void traverse() {
    if (last == NULL) {
        printf("Empty list.\n");
        return;
    }
    struct Node *temp = last->next;
    printf("CLL: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

void insert_beg(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insert_end(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void delete_beg() {
    if (last == NULL) {
        printf("Empty list.\n");
        return;
    }
    struct Node *temp = last->next;
    if (last == last->next) {
        last = NULL;
    } else {
        last->next = temp->next;
    }
    printf("Deleted node with value %d from beginning.\n", temp->data);
    free(temp);
}

void delete_end() {
    if (last == NULL) {
        printf("Empty list.\n");
        return;
    }
    struct Node *temp = last->next;
    if (last == last->next) {
        printf("Deleted node with value %d from end.\n", last->data);
        free(last);
        last = NULL;
    } else {
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = last->next;
        printf("Deleted node with value %d from end.\n", last->data);
        free(last);
        last = temp;
    }
}

int main() {
    int choice, value;
    do {
        printf("\nMenu:\n");
        printf("1. Create Nodes\n");
        printf("2. Traverse\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_nodes();
                break;
            case 2:
                traverse();
                break;
            case 3:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insert_beg(value);
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insert_end(value);
                break;
            case 5:
                delete_beg();
                break;
            case 6:
                delete_end();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
