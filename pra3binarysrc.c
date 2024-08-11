#include <stdio.h>

int main() {
    int n, i, j, temp, src, beg, end, mid;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("Enter the element to search: ");
    scanf("%d", &src);
    beg = 0;
    end = n - 1;
    int found = 0; 

    while (beg <= end) {
        mid = beg + (end - beg) / 2;

        if (a[mid] == src) {
            printf("Element found at index: %d\n", mid);
            found = 1;
            break;  
        }

        if (a[mid] < src) {
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    if (!found) {
        printf("Element not found in the array.\n");
    }
}
