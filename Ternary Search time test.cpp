///Ternary_Search_Time_Test

#include<bits/stdc++.h>
using namespace std;
int ternarySerach(int arr[],int left,int right,int target)
{
    if(left<=right)
    {
        int mid1 = left+(right-left)/3;
        int mid2 = right-(right-left)/3;

        if(target == arr[mid1]) return mid1;
        if(target == arr[mid2]) return mid2;
        if(target < arr[mid1]) return ternarySerach(arr,left,mid1-1,target);
        else if(target > arr[mid2]) return ternarySerach(arr,mid2+1,right,target);
        else return ternarySerach(arr,mid1+1,mid2-1,target);

    }
    return -1;
}

int main()
{

    int n = 14;

    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};

    int target = 9;


    int res = ternarySerach(arr,0,n-1,target);
    if(res != -1) cout<<"pos is : "<<res<<endl;
    else cout<<"Not found."<<endl;


    return 0;
}