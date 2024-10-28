//MergeShortDescending

#include <stdio.h>

void marge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int tem[right - left + 1];

    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] >= arr[j]) { // Change to descending order
            tem[k] = arr[i];
            i++;
        } else {
            tem[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        tem[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        tem[k] = arr[j];
        j++;
        k++;
    }

    // Copy the sorted subarray back to the original array
    for (int t = 0; t < k; t++) {
        arr[left + t] = tem[t];
    }
}

void margesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        margesort(arr, left, mid);
        margesort(arr, mid + 1, right);
        marge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {4, 3, 1, 1, 1, 1, 6, 6, 7, 8, 8, 9, 0, 10, -4, -2, -100, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    margesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
