//Binary binarySearch


#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (target == arr[mid]) return mid;
        if (target < arr[mid]) return binarySearch(arr, left, mid - 1, target);
        else return binarySearch(arr, mid + 1, right, target);
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

    int res = binarySearch(arr, 0, n - 1, target);
    if (res != -1) {
        printf("Position is: %d\n", res);
    } else {
        printf("Not found.\n");
    }

    return 0;
}
