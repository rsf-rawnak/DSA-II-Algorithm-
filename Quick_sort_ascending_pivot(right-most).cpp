

/**

       *** Quick Sort in Ascending Order...
       *** Pivot is right most index...



*/





#include<bits/stdc++.h>
using namespace std;


int partition(int arr[],int left,int right)
{

    int pivot = arr[right];
    int i = left;
    int j = right-1;

    while(i<=j)            ///change
        {

            while(arr[i] <= pivot && i< right) i++;      ///change
            while(arr[j] > pivot && j >= left) j--;     ///change

            if(i<j)
                {
                    swap(arr[i],arr[j]);
                    i++;
                    j--;
                }

        }

    swap(arr[right],arr[i]);
    return i;



}






void QuickSort(int arr[],int left,int right)
{

    if(left<right)
        {
            int loc = partition(arr,left,right);
            QuickSort(arr,left,loc-1);
            QuickSort(arr,loc+1,right);

        }

}

void print(int arr[],int n)
{

    for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
    cout<<endl;
}

int main()
{

    int arr[] = {6,1,5,7,3,3,5,5,8,9,0,1,0,0,5,3,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"BEFORE SORTED : ";
    print(arr,n);

    QuickSort(arr,0,n-1);

    cout<<"AFTER SORTED : ";
    print(arr,n);


    return 0;
}


