#include <stdio.h>

int binary(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (target == arr[mid]) return mid;
        if (target < arr[mid]) return binary(arr, left, mid - 1, target); // Corrected order
        else return binary(arr, mid + 1, right, target);
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Sorted array for binary search
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Enter your target value: ");
    int target;
    scanf("%d", &target);

    int res = binary(arr, 0, n - 1, target);

    if (res != -1)
        printf("Target found at index: %d\n", res);
    else
        printf("Not found -_-\n");

    return 0;
}
