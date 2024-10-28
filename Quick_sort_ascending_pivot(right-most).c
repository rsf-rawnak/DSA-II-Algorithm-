#include <stdio.h>

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;
    int j = right - 1;

    while (i <= j) {
        while (i < right && arr[i] <= pivot) i++;
        while (j >= left && arr[j] > pivot) j--;

        if (i < j) {
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    // Swap arr[right] and arr[i]
    arr[right] = arr[i];
    arr[i] = pivot;
    return i;
}

void QuickSort(int arr[], int left, int right) {
    if (left < right) {
        int loc = partition(arr, left, right);
        QuickSort(arr, left, loc - 1);
        QuickSort(arr, loc + 1, right);
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {6, 1, 5, 7, 3, 3, 5, 5, 8, 9, 0, 1, 0, 0, 5, 3, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("BEFORE SORTED: ");
    print(arr, n);

    QuickSort(arr, 0, n - 1);

    printf("AFTER SORTED: ");
    print(arr, n);

    return 0;
}
