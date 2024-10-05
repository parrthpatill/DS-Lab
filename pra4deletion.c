#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
int main() {
    struct node* start = NULL;
    struct node* newNode, * temp, * prev;
    int choice, position;
    char ch;
    do {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter value for the node: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (start == NULL) {
            start = newNode;
        } else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            } temp->next = newNode;
        }
        printf("Press y/Y to add another node: ");
        getchar();
        ch = getchar();
    } while (ch == 'y' || ch == 'Y');
    do {
        printf("\n1. Delete at beginning\n");
        printf("2. Delete at end\n");
        printf("3. Delete at specific position\n");
        printf("4. Display list\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (start == NULL) {
                    printf("List is empty, nothing to delete\n");
                } else {
                    temp = start;
                    start = start->next;
                    free(temp);
                    printf("Node deleted from the beginning.\n");
                } break;
            case 2:
                if (start == NULL) {
                    printf("List is empty, nothing to delete\n");
                } else if (start->next == NULL) {
                    free(start);
                    start = NULL;
                    printf("Node deleted from the end.\n");
                } else {
                    temp = start;
                    while (temp->next->next != NULL) {
                        temp = temp->next;
                    }
                    free(temp->next);
                    temp->next = NULL;
                    printf("Node deleted from the end.\n");
                } break;

            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                if (start == NULL) {
                    printf("List is empty, nothing to delete\n");
                } else if (position == 1) {
                    temp = start;
                    start = start->next;
                    free(temp);
                    printf("Node deleted from position 1.\n");
                } else {
                    temp = start;
                    prev = NULL;
                    for (int i = 1; i < position && temp != NULL; i++) {
                        prev = temp;
                        temp = temp->next;
                    }
                    if (temp == NULL) {
                        printf("Position out of bounds\n");
                    } else {
                        prev->next = temp->next;
                        free(temp);
                        printf("Node deleted from position %d.\n", position);
                    }
                } break;
            case 4:
                temp = start;
                printf("Linked list:\n");
                while (temp != NULL) {
                    printf("%d ", temp->data);
                    temp = temp->next;
                } break;
            default:
                printf("Invalid choice\n");
        } printf("Press y/Y to continue: ");
        getchar();
        ch = getchar();
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
