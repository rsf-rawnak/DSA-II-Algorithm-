#include<bits/stdc++.h>
using namespace std;

int ternary(int arr[], int left, int right, int target)
{
    if (left <= right)
        {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;


            if (target == arr[mid1]) return mid1;
            if (target == arr[mid2]) return mid2;
            if (target > arr[mid1]) return ternary(arr, left, mid1 - 1, target);
            else if (target < arr[mid2]) return ternary(arr, mid2 + 1, right, target);
            else return ternary(arr, mid1 + 1, mid2 - 1, target);
        }

    return -1; // Element not found
}

int main()
{
    int arr[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Enter the target value: ";
    int target;
    cin >> target;

    int res = ternary(arr, 0, n - 1, target);

    if (res != -1)
        cout << "Target found at index: " << res << endl;
    else
        cout << "NO" << endl;

    return 0;
}
