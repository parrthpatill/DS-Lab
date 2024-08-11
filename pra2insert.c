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
    printf("Choose pos for insertion:\n 1.beginning\n 2.end\n 3.specific position\n");
    scanf("%d", &c);
    switch (c){
    case 1:
        printf("enter element:\n");
        scanf("%d", &v);
        for(i = n; i > 0; i--){
            a[i] = a[i-1];
        }
        a[0] = v;
        n++;
        break;
    case 2:
        printf("enter element:\n");
        scanf("%d", &v);
        a[n] = v;
        n++;
        break;
    case 3:
        printf("enter pos:\n");
        scanf("%d", &p);
        printf("enter element:\n");
        scanf("%d", &v);
        for(i = n; i >= p; i--){
            a[i] = a[i-1];
        }
        a[p-1] = v;
        n++;
        break;
    default:
        printf("invalid choice\n");
    }
    printf("new array:\n");
    for(i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}
