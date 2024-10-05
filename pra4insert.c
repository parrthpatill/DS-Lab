#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
int main() {
    struct node* start = NULL;
    struct node* newNode, * temp;
    int choice, value, position;
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
            }
            temp->next = newNode;
        }
        printf("Press y/Y to add another node: ");
        getchar();
        ch = getchar();
    } while (ch == 'y' || ch == 'Y');
    do {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
        printf("4. Display list\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                newNode = (struct node*)malloc(sizeof(struct node));
                printf("Enter value to insert at beginning: ");
                scanf("%d", &newNode->data);
                newNode->next = start;
                start = newNode;
                break;
            case 2:
                newNode = (struct node*)malloc(sizeof(struct node));
                printf("Enter value to insert at end: ");
                scanf("%d", &newNode->data);
                newNode->next = NULL;
                if (start == NULL) {
                    start = newNode;
                } else {
                    temp = start;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                } break;
            case 3:
            newNode = (struct node*)malloc(sizeof(struct node));
            printf("Enter value to insert: ");
            scanf("%d", &newNode->data);
            printf("Enter position: ");
            scanf("%d", &position);
            if (position == 1) {
                newNode->next = start;
                start = newNode;
            } else {
                temp = start;
                for (int i = 1; i < position - 1 && temp != NULL; i++) {
                    temp = temp->next;
                }
                if (temp == NULL) {
                    printf("Position out of bounds\n");
                    free(newNode);  
                } else {
                    newNode->next = temp->next;
                    temp->next = newNode;
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
        }
        printf("Press y/Y to continue: ");
        getchar();
        ch = getchar();
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
