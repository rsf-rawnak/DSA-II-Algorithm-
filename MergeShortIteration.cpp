//MergeShortIteration



#include<bits/stdc++.h>
using namespace std;

void marge(int arr[],int left,int mid,int right)
{

    ///    ***
    cout<<"initial "<<left<<" "<<right<<endl;
    for(int i = left; i<=right; i++)cout<<arr[i]<<" ";
    cout<<endl;


    int i = left;
    int j = mid+1;
    int tem[right-left+1];

    int k =0;

    while(i <= mid && j<= right)
        {

            if(arr[i] <= arr[j])
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
    cout<<"after marge "<<left<<" "<<right<<endl;
    for(int i = left; i<=right; i++)cout<<arr[i]<<" ";
    cout<<endl;

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


    int arr[] = {5,1,3,2,4,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    margesort(arr,0,n-1);

    for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
    cout<<endl;

}

