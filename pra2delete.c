#include <stdio.h>
int main() {
    int n, v, p, i, c;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Choose pos for deletion:\n 1.beginning\n 2.end\n 3.specific position\n");
    scanf("%d", &c);
    switch (c){
    case 1:
        for(i = 0; i < n-1; i++){
            a[i] = a[i+1];
        }
        n--;
        break;
    case 2:
        n--;
        break;
    case 3:
        printf("enter pos:\n");
        scanf("%d", &p);
        for(i = p-1; i < n-1; i++){
            a[i] = a[i+1];
        }
        n--;
        break;
    default:
        printf("invalid\n");
    }
    printf("new array:\n");
    for(i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}
