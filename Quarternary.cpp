///Quatarnary_Search

#include<bits/stdc++.h>
using namespace std;
int quaterSerach(int arr[],int left,int right,int target)
{
    if(left<=right)
    {
        int mid1 = left+(right-left)/4;
        int mid2 = left+(right-left)/2;
        int mid3 = right-(right-left)/4;

        if(target == arr[mid1]) return mid1;
        if(target == arr[mid2]) return mid2;
        if(target == arr[mid3]) return mid3;
        if(target < arr[mid1]) return quaterSerach(arr,left,mid1-1,target);
        else if(target > arr[mid3]) return quaterSerach(arr,mid3+1,right,target);
        else if(target>arr[mid1] && target<arr[mid2] ) return quaterSerach(arr,mid1+1,mid2-1,target);
        else if(target>arr[mid2] && target<arr[mid3] ) return quaterSerach(arr,mid2+1,mid3-1,target);


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

    int res = quaterSerach(arr,0,n-1,target);
    if(res != -1) cout<<"pos is : "<<res<<endl;
    else cout<<"Not found."<<endl;


    return 0;
}
