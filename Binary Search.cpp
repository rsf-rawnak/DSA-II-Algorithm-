
///Binary_Search

#include<bits/stdc++.h>
using namespace std;
int binarySerach(int arr[],int left,int right,int target)
{
    if(left<=right)
    {
        int mid = left+(right-left)/2;
        if(target == arr[mid]) return mid;
        if(target < arr[mid]) return binarySerach(arr,left,mid-1,target);
        else return binarySerach(arr,mid+1,right,target);
    }
    return -1;
}

int main()
{

    cout<<"Enter the size of array"<<endl;

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter the target element"<<endl;
    int target;
    cin>>target;

    int res = binarySerach(arr,0,n-1,target);
    if(res != -1) cout<<"pos is : "<<res<<endl;
    else cout<<"Not found."<<endl;


    return 0;
}

