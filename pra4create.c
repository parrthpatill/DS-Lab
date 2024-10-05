#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
int main() {
    char ch;
    struct node *a, *b, *start;
    a = (struct node*)malloc(sizeof(struct node));
    printf("First node value: ");
    scanf("%d", &a->data);
    a->next = NULL;
    start = a;
    do {
        b = (struct node*)malloc(sizeof(struct node));
        printf("Enter next node value: ");
        scanf("%d", &b->data);
        b->next = NULL;
        a->next = b;
        a = b;
        printf("Press y/Y to create more nodes: ");
        getchar(); 
        ch = getchar();
    } while (ch == 'y' || ch == 'Y');
    b = start;
    while (b != NULL) {
        printf("%d\n", b->data);
        b = b->next;
    }
}
