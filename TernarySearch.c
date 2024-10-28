#include <stdio.h>

int ternarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (target == arr[mid1]) return mid1;
        if (target == arr[mid2]) return mid2;
        if (target < arr[mid1]) return ternarySearch(arr, left, mid1 - 1, target);
        else if (target > arr[mid2]) return ternarySearch(arr, mid2 + 1, right, target);
        else return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
    }
    return -1;
}

int main() {
    printf("Enter the size of array: ");
    int n;
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element: ");
    int target;
    scanf("%d", &target);

    int res = ternarySearch(arr, 0, n - 1, target);
    if (res != -1) 
        printf("Position is: %d\n", res);
    else 
        printf("Not found.\n");

    return 0;
}
