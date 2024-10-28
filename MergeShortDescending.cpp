

/// marge decscending


#include<bits/stdc++.h>
using namespace std;

void marge(int arr[],int left,int mid,int right)
{

    int i = left;
    int j = mid+1;
    int tem[right-left+1];

    int k =0;

    while(i <= mid && j<= right)
        {

            if(arr[i] >= arr[j])
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

    int t = 0;

    for(int i =left; i<=right; i++)
        {
            arr[i] = tem[t];
            t++;
        }


}







void margesort(int arr[],int left,int right)
{


    if(left<right)
        {

            int mid =  left+(right-left)/2;
            margesort(arr,left,mid);
            margesort(arr,mid+1,right);


            marge(arr,left,mid,right);
        }



}



int main()
{

    int arr[] = { 4,3,1,1,1,1,6,6,7,8,8,9,0,10,-4,-2,-100,12};
    int n = sizeof(arr)/sizeof(arr[0]);

    margesort(arr,0,n-1);

    for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
    cout<<endl;

}
