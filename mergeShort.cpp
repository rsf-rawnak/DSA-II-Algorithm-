/// Merge_Sort

#include<bits/stdc++.h>
using namespace std;


void merge_(int arr[],int left,int mid,int right)
{

    int i=left;
    int j=mid+1;
    int k=0;

    int tem[right-left+1];

    while(i<=mid && j<=right)
        {
            if(arr[i]<=arr[j])
                {
                    tem[k] = arr[i];
                    i++;
                }
            else
                {
                    tem[k] = arr[j];
                    j++;
                }
            k++;
        }


    while(i<=mid)
        {
            tem[k] = arr[i];
            i++;
            k++;
        }

    while(j<=right)
        {
            tem[k] = arr[j];
            j++;
            k++;
        }

    k=0;

    for(int i=left; i<=right; i++)
        {
            arr[i] = tem[k];
            k++;
        }

}



void mergeSort(int arr[],int left,int right)
{

    if(left<right)
        {
            int mid = left+(right-left)/2;

            mergeSort(arr,left,mid);
            mergeSort(arr,mid+1,right);

            merge_(arr,left,mid,right);

        }


}

void print(int arr[],int size)
{

    for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<" ";
        }
    cout<<endl;
}


int main()
{
    cout<<"Enter the size of array : ";

    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++) cin>>arr[i];

    mergeSort(arr,0,n-1);

    print(arr,n);


    return 0;
}
