#include <stdio.h>
int main() {
    int n, i, x, found = 0;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the search element: ");
    scanf("%d", &x);
    for(i = 0; i < n; i++) {
        if(a[i] == x) {
            found = 1;
            break;
        }
    }
    if(found == 1) {
        printf("Element is present");
    } else {
        printf("Element is not present");
    }
}
