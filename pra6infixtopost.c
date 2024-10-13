#include <stdio.h>
#define MAX 100
struct Stack {
    int top;
    char arr[MAX];
};
void push(struct Stack* s, char ch) {
    if (s->top < MAX - 1) {
        s->arr[++s->top] = ch;
    }
}
char pop(struct Stack* s) {
    if (s->top >= 0) {
        return s->arr[s->top--];
    }
    return '\0';
}
int isEmpty(struct Stack* s) {
    return s->top == -1;
}
int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
void reverse(char* str) {
    int len = 0;
    while (str[len] != '\0') len++;

    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    s.top = -1;
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] >= 'a' && infix[i] <= 'z') { 
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') { 
            push(&s, infix[i]);
        } else if (infix[i] == ')') { 
            while (!isEmpty(&s) && s.arr[s.top] != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); 
        } else { 
            while (!isEmpty(&s) && precedence(s.arr[s.top]) >= precedence(infix[i])) {
                postfix[k++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }

    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0'; 
}

void infixToPrefix(char* infix, char* prefix) {
    reverse(infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    infixToPostfix(infix, prefix);
    reverse(prefix);
}

int evaluatePostfix(char* postfix) {
    struct Stack s;
    s.top = -1;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(&s, postfix[i] - '0');
        } else {
            int val1 = pop(&s);
            int val2 = pop(&s);
            switch (postfix[i]) {
                case '+': push(&s, val2 + val1); break;
                case '-': push(&s, val2 - val1); break;
                case '*': push(&s, val2 * val1); break;
                case '/': push(&s, val2 / val1); break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Infix to Postfix\n");
        printf("2. Infix to Prefix\n");
        printf("3. Evaluation of Postfix Expression\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter infix expression: ");
            scanf("%s", infix);
            infixToPostfix(infix, postfix);
            printf("Postfix: %s\n", postfix);
        } else if (choice == 2) {
            printf("Enter infix expression: ");
            scanf("%s", infix);
            infixToPrefix(infix, prefix);
            printf("Prefix: %s\n", prefix);
        } else if (choice == 3) {
            printf("Enter postfix expression: ");
            scanf("%s", postfix);
            printf("Result: %d\n", evaluatePostfix(postfix));
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
