
#include<bits/stdc++.h>
using namespace std;

int binary(int arr[], int left, int right, int target)
{
    if (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target == arr[mid])return mid;
            if (target < arr[mid]) return binary(arr, mid + 1, right, target);
            else return binary(arr, left, mid - 1, target);
        }
    return -1;
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Enter your target value: ";

    int target;
    cin >> target;

    int res = binary(arr, 0, n - 1, target);

    if (res != -1)
        cout << "Target found at index: " << res << endl;
    else
        cout << "Not found -_-" << endl;

    return 0;
}