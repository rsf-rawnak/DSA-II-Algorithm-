#include<stdio.h>
int freq[5];
int coinChange(int n, int c[], int i)
{
    if(n==0) return 0;
    else if(c[i]<=n)
    {
        freq[i]++;
        return 1+coinChange(n - c[i], c, i);
    }
    else
    {
        return coinChange(n, c, i+1);
    }
}
int main()
{
    int n = 87;
    int m = 5;
    int c[m] = {50,25,10,5,1};

    int numCoins = coinChange(n, c, 0);
    printf("numCoins = %d\n", numCoins);

    for(int i=0; i<m; i++)
    {
        printf("%d ", freq[i]);
    }
}