#include <stdio.h>
int main() {
    int i, j, min, temp, n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
    }
}
