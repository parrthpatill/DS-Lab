#include <stdio.h>
#include <stdlib.h>
#define size 5
int stack[size];
int top = -1;    

int main() {
    int c = 0, x;
    while(c != 4){  
        printf("Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("choose stack operation: ");
        scanf("%d", &c); 
        switch (c) {
            case 1:
                if (top == size - 1) {
                    printf("stack overflow.\n");
                } else {
                    printf("value: ");
                    scanf("%d", &x);
                    top++;
                    stack[top] = x;
                }
                break;
            case 2:
                if (top == -1) {
                    printf("stack underflow\n");
                } else {
                    top--;
                }
                break;
            case 3:
                if (top == -1) {
                    printf("empty stack.\n");
                } else {
                    printf("Stack: ");
                    for (int i = 0; i <= top; i++) {
                    printf("%d\n ", stack[i]);
                    }
                }
                break;
            case 4:
                printf("exiting");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}
